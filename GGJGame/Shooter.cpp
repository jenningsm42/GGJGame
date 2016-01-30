#include "Shooter.h"

Shooter::Shooter()
{
}

Shooter::~Shooter()
{
}

void Shooter::initialize(Map &)
{
	m_texture.loadFromFile("data/shooter.png");
	m_sprite.setTexture(m_texture);
	//m_sprite.setPosition(x, y);
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
