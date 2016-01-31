#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <SFML/Graphics.hpp>
#include "ProjectileType.h"
class Enemy;

class Projectile
{
public:
    Projectile(sf::Texture&, sf::Vector2f spawn, Enemy* target, ProjectileType type);
    Projectile(const Projectile&);
    ~Projectile();
    
	bool update(float dt);
    void draw(sf::RenderWindow&);
    
    const sf::FloatRect getBounds() const;
    const sf::Vector2f getCenter() const;
    
    Projectile& operator=(const Projectile&);
    
private:
    sf::Sprite m_sprite;
    ProjectileType m_type;
    Enemy* m_target;
    float m_speed;
};

#endif // PROJECTILE_H
