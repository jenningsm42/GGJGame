#include "Enemy.h"

void Enemy::damage(int amount)
{
	m_health-=amount;
}

int Enemy::getHealth()
{
	return m_health;
}

void Enemy::damageOverTime(int damage)
{
	DotDuration = 5;
    m_dotDamage = damage;
}

void Enemy::slow()
{
	slowDuration = 6;
}

const sf::FloatRect Enemy::getBounds() const
{
	return m_sprite.getGlobalBounds();
}

const sf::Vector2f Enemy::getCenter() const
{
	return m_sprite.getPosition() + 0.5f * sf::Vector2f(m_sprite.getLocalBounds().width, m_sprite.getLocalBounds().height);
}

void Enemy::setTarget(sf::Vector2f target)
{
    m_target = target;
}

void Enemy::assignRitualist(int index)
{
    m_ritualist = index;
}

int Enemy::getAssignedRitualist()
{
    return m_ritualist;
}