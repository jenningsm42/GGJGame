#include "WorkerPool.h"

WorkerPool::WorkerPool() : m_workerCount(5)
{
}

WorkerPool::~WorkerPool()
{
}

void WorkerPool::initialize(Map& map)
{
    for(int i = 0; i < m_workerCount; i++)
        m_workers[i].initialize(map);
}

void WorkerPool::update(float dt)
{
    for(int i = 0; i < m_workerCount; i++)
        m_workers[i].update(dt);//, <#Application *#>)
}

void WorkerPool::draw(sf::RenderWindow& window)
{
    for(int i = 0; i < m_workerCount; i++)
        m_workers[i].draw(window);
}