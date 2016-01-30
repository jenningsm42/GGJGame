#include "WorkerPool.h"
#include "Application.h"

WorkerPool::WorkerPool() : m_workerCount(5), m_selectedWorker(-1)
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

void WorkerPool::update(float dt, Application* app, Map& map)
{
    bool uiUpdate = false;
    if(m_selectedWorker != -1)
        uiUpdate = m_weaponsUI.update(app);
    
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !uiUpdate)
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
    
    if(sf::Mouse::isButtonPressed(sf::Mouse::Right) && m_selectedWorker != -1 && !uiUpdate)
    {
        sf::Vector2i mpos = sf::Mouse::getPosition();
        mpos.x += app->getView()->getCenter().x - app->getWidth() / 2;
        mpos.y += app->getView()->getCenter().y - app->getHeight() / 2;
        
        Command c;
        c.commandType = CommandType::Move;
        sf::Vector2f cellPos = map.convertToCellCoordinates(mpos.x, mpos.y);
        c.x = cellPos.x;
        c.y = cellPos.y;
        
        m_workers[m_selectedWorker].setCommand(c);
    }
    
    for(int i = 0; i < m_workerCount; i++)
    {
        m_workers[i].update(dt);
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