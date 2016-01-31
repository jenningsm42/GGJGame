#include "Tower.h"

Tower::Tower()
{
}

Tower::~Tower()
{
}

void Tower::initialize(Map &, float x, float y, sf::Texture& texture)
{
	m_sprite.setTexture(texture);
	m_sprite.setPosition(x - texture.getSize().x / 2, y - texture.getSize().y + 20);
}

void Tower::release()
{
}

void Tower::update(float dt, EnemyPool& enemyPool, ProjectilePool& projectilePool)
{
	static sf::Clock timer;
	if (timer.getElapsedTime().asSeconds() >= m_delay)
	{
		sf::Vector2f spos = m_sprite.getPosition();
		spos.x += m_sprite.getLocalBounds().width / 2;
		spos.y += m_sprite.getLocalBounds().height / 2;

		for (int i = 0; i < enemyPool.size(); i++)
		{
			sf::Vector2f dpos = enemyPool.getEnemy(i).getCenter() - spos;
			float lenSq = dpos.x*dpos.x + dpos.y*dpos.y;

			if (lenSq < m_rangeSq)
			{
				projectilePool.spawnProjectile(spos.x, spos.y, &enemyPool.getEnemy(i), ProjectileType::Dart);
				timer.restart();
				break;
			}
		}
	}
}

void Tower::draw(sf::RenderWindow &window)
{
	window.draw(m_sprite);
}
