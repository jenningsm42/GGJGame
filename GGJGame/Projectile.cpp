#include "Projectile.h"
#include "Enemy.h"
#include <cmath>

Projectile::Projectile(sf::Texture& texture, sf::Vector2f spawn, Enemy* target) : m_speed(700.f), m_target(target)
{
    m_sprite.setTexture(texture);
    m_sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    m_sprite.setPosition(spawn);
}

Projectile::~Projectile()
{
}

bool Projectile::update(float dt)
{
    if(m_target == nullptr)
        return true;
    
    sf::Vector2f tpos = m_target->getCenter();
    
    float dx = tpos.x - getCenter().x;
    float dy = tpos.y - getCenter().y;
    
    if(fabsf(dx) < 10.f && fabsf(dy) < 10.f)
    {
        m_target->damage();
        return true; // hit target
    }
    
    float angle = atan2f(dy, dx);

    m_sprite.setRotation(angle);
    m_sprite.move(m_speed * cosf(angle) * dt, m_speed * sinf(angle) * dt);
    
    return false;
}

const sf::FloatRect Projectile::getBounds() const
{
    return m_sprite.getGlobalBounds();
}

const sf::Vector2f Projectile::getCenter() const
{
    return m_sprite.getPosition() + 0.5f * sf::Vector2f(m_sprite.getLocalBounds().width, m_sprite.getLocalBounds().height);
}