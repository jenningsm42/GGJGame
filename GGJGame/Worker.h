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
    
    void update(float dt);
    void draw(sf::RenderWindow&) override;
    
    const sf::FloatRect& getBounds() const;
    const sf::Vector2f& getCenter() const;
};

#endif // WORKER_H
