#ifndef WORKERPOOL_H
#define WORKERPOOL_H
#include <SFML/Graphics.hpp>
#include "Worker.h"
#include "Map.h"

class WorkerPool
{
public:
    WorkerPool();
    ~WorkerPool();
    
    void initialize(Map&);
    
    void update(float dt);
    void draw(sf::RenderWindow&);
    
private:
    Worker m_workers[10];
    int m_workerCount;
};

#endif // WORKERPOOL_H
