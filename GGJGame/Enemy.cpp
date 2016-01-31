#include "Enemy.h"

void Enemy::damage()
{
	m_health--;
}

int Enemy::getHealth()
{
	return m_health;
}