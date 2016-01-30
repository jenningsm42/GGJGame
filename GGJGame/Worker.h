#ifndef WORKER_H
#define WORKER_H
#include "GameObject.h"
#include "Map.h"

class Worker : public GameObject
{
public:
    Worker();
    ~Worker();
    
    void initialize(Map& map);
    void release() override;
    
    void update(float dt, Application*) override;
    void draw(sf::RenderWindow&) override;
};

#endif // WORKER_H
