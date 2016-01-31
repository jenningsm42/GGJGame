#include "WorkerPool.h"
#include "Application.h"
#include <cmath>

WorkerPool::WorkerPool() : m_workerCount(5), m_selectedWorker(-1), placeWeapon(false)
{
}

WorkerPool::~WorkerPool()
{
}

void WorkerPool::initialize(Map& map, Application* app)
{
    m_selectedTexture.loadFromFile("data/selected.png");
    m_selectedSprite.setTexture(m_selectedTexture);
    
    for(int i = 0; i < m_workerCount; i++)
        m_workers[i].initialize(map);
    
    m_weaponsUI.initialize(app);
}

void WorkerPool::update(float dt, Application* app, Map& map, WeaponPool &weaponPool)
{
	weapon weaponToPlace;
    if(m_selectedWorker != -1)
    {
		m_weaponsUI.update(app, weaponToPlace);
        if(!placeWeapon)
            placeWeapon = (weaponToPlace.weapontype != weapontype::none);
    }
    
    // Selecting a worker
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !weaponToPlace.isHover && !placeWeapon)
    {
        sf::Vector2i mpos = sf::Mouse::getPosition();
        mpos.x += app->getView()->getCenter().x - app->getWidth() / 2;
        mpos.y += app->getView()->getCenter().y - app->getHeight() / 2;
        
        m_selectedWorker = -1;
        for(int i = 0; i < m_workerCount; i++)
        {
            if(m_workers[i].getBounds().contains(mpos.x, mpos.y))
                m_selectedWorker = i;
        }
    }
    
    // Moving a worker
    if(sf::Mouse::isButtonPressed(sf::Mouse::Right) && m_selectedWorker != -1 && !weaponToPlace.isHover && !placeWeapon)
    {
        sf::Vector2i mpos = sf::Mouse::getPosition();
        mpos.x += app->getView()->getCenter().x - app->getWidth() / 2;
        mpos.y += app->getView()->getCenter().y - app->getHeight() / 2;
        
        if(validMove(mpos.x, mpos.y, map))
        {
            Command c;
            c.commandType = CommandType::Move;
            sf::Vector2f cellPos = map.convertToCellCoordinates(mpos.x, mpos.y);
            c.x = cellPos.x;
            c.y = cellPos.y;
            
            m_workers[m_selectedWorker].setCommand(c);
        }
    }

    // Placing a weapon
	if (placeWeapon && sf::Mouse::isButtonPressed(sf::Mouse::Left) && !weaponToPlace.isHover) {
		sf::Vector2i mpos = sf::Mouse::getPosition();
		mpos.x += app->getView()->getCenter().x - app->getWidth() / 2;
		mpos.y += app->getView()->getCenter().y - app->getHeight() / 2;
		
        if(validMove(mpos.x, mpos.y, map))
        {
            Command c;
            c.commandType = CommandType::Place;
            c.weapontype = weaponToPlace.weapontype;
            sf::Vector2f cellPos = map.convertToCellCoordinates(mpos.x, mpos.y);
            c.x = cellPos.x;
            c.y = cellPos.y;

            m_workers[m_selectedWorker].setCommand(c);
            
            placeWeapon = false;
        }
	}
    
    for(int i = 0; i < m_workerCount; i++)
    {
        m_workers[i].update(dt, map, weaponPool);
        if(m_selectedWorker == i)
            m_selectedSprite.setPosition(m_workers[i].getCenter().x - m_selectedTexture.getSize().x / 2,
                                         m_workers[i].getCenter().y - 70);
    }
}

void WorkerPool::draw(sf::RenderWindow& window)
{
    for(int i = 0; i < m_workerCount; i++)
        m_workers[i].draw(window);
    
    if(m_selectedWorker != -1)
    {
        window.draw(m_selectedSprite);
        m_weaponsUI.draw(window);
    }
}

bool WorkerPool::validMove(float x, float y, Map& map)
{
    sf::Vector2f c = map.convertToCellCoordinates(x, y);
    
    float spawnDistance = 150.f;
    
    float dx = c.x - map.getWidth() / 2;
    float dy = c.y - map.getHeight() / 2;
    
    if(fabsf(dx) < spawnDistance && fabsf(dy) < spawnDistance)
        return false;
    
    for(int i = 0; i < m_workerCount; i++)
    {
        if(m_workers[i].getBounds().contains(x, y))
            return false;
    }
    
    return true;
}