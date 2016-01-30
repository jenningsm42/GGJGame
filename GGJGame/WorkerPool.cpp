#include "WorkerPool.h"

WorkerPool::WorkerPool() : m_workerCount(5), m_selectedWorker(-1)
{
}

WorkerPool::~WorkerPool()
{
}

void WorkerPool::initialize(Map& map)
{
    m_selectedTexture.loadFromFile("data/selected.png");
    m_selectedSprite.setTexture(m_selectedTexture);
    
    for(int i = 0; i < m_workerCount; i++)
        m_workers[i].initialize(map);
}

void WorkerPool::update(float dt)
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2i mpos = sf::Mouse::getPosition();
        
        m_selectedWorker = -1;
        for(int i = 0; i < m_workerCount; i++)
        {
            if(m_workers[i].getBounds().contains(mpos.x, mpos.y))
                m_selectedWorker = i;
        }
    }
    
    for(int i = 0; i < m_workerCount; i++)
    {
        m_workers[i].update(dt);
        if(m_selectedWorker == i)
            m_selectedSprite.setPosition(m_workers[i].getCenter().x - m_selectedTexture.getSize().x / 2,
                                         m_workers[i].getCenter().y - m_selectedTexture.getSize().y / 2);
    }
}

void WorkerPool::draw(sf::RenderWindow& window)
{
    for(int i = 0; i < m_workerCount; i++)
        m_workers[i].draw(window);
    
    if(m_selectedWorker != -1)
        window.draw(m_selectedSprite);
}