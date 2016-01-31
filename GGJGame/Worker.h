#ifndef WORKER_H
#define WORKER_H
#include "GameObject.h"
#include "Map.h"
#include "Command.h"
#include "Shooter.h"
#include "Weapon.h"
#include "WeaponPool.h"

class Worker : public GameObject
{
public:
    Worker();
    ~Worker();
    
    void initialize(Map& map);
    void release() override;
    
    void update(float dt, Map &map, WeaponPool &weaponPool);
    void draw(sf::RenderWindow&) override;
    
    const sf::FloatRect getBounds() const;
    const sf::Vector2f getCenter() const;
    
    void setCommand(Command&);
    
private:
    Command m_curCommand;
    const float m_speed;
};

#endif // WORKER_H
