#ifndef WORKER_H
#define WORKER_H
#include "GameObject.h"
#include "Map.h"
#include "Command.h"
#include "WeaponPool.h"
#include "EnemyPool.h"
#include "Bar.h"

class Worker : public GameObject
{
public:
    Worker();
    ~Worker();
    
    void initialize(Map& map);
    void release() override;
    
    void update(float dt, Map &map, WeaponPool &weaponPool, EnemyPool& enemyPool);
    void draw(sf::RenderWindow&) override;
    
    void damage();
    int getHealth();
    
    const sf::FloatRect getBounds() const;
    const sf::Vector2f getCenter() const;
    
    void setCommand(Command&);
    
private:
    Command m_curCommand;
    const float m_speed;
    int m_health;
	sf::Texture m_texture[3];
	sf::Sprite m_sprite;
    sf::Clock m_buildTimer;
    bool m_building;
    sf::Texture m_moveTileTexture;
    sf::Sprite m_moveTileSprite;
    Bar m_buildBar;
};

#endif // WORKER_H
