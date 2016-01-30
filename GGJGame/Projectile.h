#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <SFML/Graphics.hpp>
class Enemy;

class Projectile
{
public:
    Projectile(sf::Texture&, sf::Vector2f spawn, Enemy* target);
    ~Projectile();
    
    bool update(float dt);
    
    const sf::FloatRect getBounds() const;
    const sf::Vector2f getCenter() const;
    
private:
    sf::Sprite m_sprite;
    Enemy* m_target;
    const float m_speed;
};

#endif // PROJECTILE_H
