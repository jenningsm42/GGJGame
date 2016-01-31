#include "Shooter.h"

Shooter::Shooter()
{
}

Shooter::~Shooter()
{
}

void Shooter::initialize(Map &, float x, float y, sf::Texture& texture)
{
    m_sprite.setTexture(texture);
	m_sprite.setPosition(x, y);
}

void Shooter::release()
{
}

void Shooter::update(float dt)
{
}

void Shooter::draw(sf::RenderWindow &window)
{
	window.draw(m_sprite);
}
