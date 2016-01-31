#include "Projectile.h"
#include "Enemy.h"
#include <cmath>

Projectile::Projectile(sf::Texture& texture, sf::Vector2f spawn, Enemy* target, ProjectileType type)
    : m_speed(700.f), m_target(target), m_type(type)
{
    m_sprite.setTexture(texture);
    m_sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    m_sprite.setPosition(spawn);
}

Projectile::Projectile(const Projectile& other)
{
    m_speed = other.m_speed;
    m_sprite = other.m_sprite;
    m_target = other.m_target;
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
		if (m_type == ProjectileType::Energy) {
			m_target->damage();
			return true; // hit target
		}
		if (m_type == ProjectileType::Acid) {
			m_target->damageOverTime();
			return true;
		}
		if (m_type == ProjectileType::Dart) {
			m_target->slow();
		}
    }
    
    float angle = atan2f(dy, dx);

    m_sprite.setRotation(360.f * angle / (2.f*3.14159f));
    m_sprite.move(m_speed * cosf(angle) * dt, m_speed * sinf(angle) * dt);
    
    return false;
}

void Projectile::draw(sf::RenderWindow& window)
{
    window.draw(m_sprite);
}

const sf::FloatRect Projectile::getBounds() const
{
    return m_sprite.getGlobalBounds();
}

const sf::Vector2f Projectile::getCenter() const
{
    return m_sprite.getPosition() + 0.5f * sf::Vector2f(m_sprite.getLocalBounds().width, m_sprite.getLocalBounds().height);
}

Projectile& Projectile::operator=(const Projectile& other)
{
    m_speed = other.m_speed;
    m_sprite = other.m_sprite;
    m_target = other.m_target;
	return *this;
}