#include "EnemyPool.h"
#include "Application.h"
#include "Ghost.h"
#include "Zombie.h"


EnemyPool::EnemyPool()
{
}

EnemyPool::~EnemyPool()
{
}

void EnemyPool::initialize(Map &)
{
	m_enemyTextures[0].loadFromFile("data/zombie.png");
	m_enemyTextures[1].loadFromFile("data/ghost.png");
}

void EnemyPool::update(float dt, Application *app, Map &map)
{
	sf::Time initialTime = initialClock.getElapsedTime();

	if (initialTime.asSeconds() > 0) {
		sf::Time timer = zombieClock.getElapsedTime();
		if (timer.asSeconds() > 5) {
			enemies.push_back(new Zombie());
			enemies.back()->initialize(map, m_enemyTextures[0]);
			zombieClock.restart();
		}
		timer = ghostClock.getElapsedTime();
		if (timer.asSeconds() > 15) {
			enemies.push_back(new Ghost());
			enemies.back()->initialize(map, m_enemyTextures[1]);
			ghostClock.restart();
		}
		for (int i = 0; i < enemies.size(); i++) {
            enemies[i]->update(dt, map);
            if(enemies[i]->getHealth() <= 0)
            {
                enemies[i]->release();
                enemies.erase(enemies.begin() + i);
            }
		}
	}
}

void EnemyPool::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->draw(window);
	}
}

int EnemyPool::size()
{
    return enemies.size();
}

Enemy& EnemyPool::getEnemy(int index)
{
    return enemies[index];
}