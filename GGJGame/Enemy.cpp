#include "Enemy.h"

void Enemy::damage()
{
	m_health--;
}

int Enemy::getHealth()
{
	return m_health;
}

const sf::FloatRect Enemy::getBounds() const
{
	return m_sprite.getGlobalBounds();
}

const sf::Vector2f Enemy::getCenter() const
{
	return m_sprite.getPosition() + 0.5f * sf::Vector2f(m_sprite.getLocalBounds().width, m_sprite.getLocalBounds().height);
}