#include "EnemyPool.h"
#include "Application.h"


EnemyPool::EnemyPool()
{
	
}

EnemyPool::~EnemyPool()
{
}

void EnemyPool::initialize(Map &)
{
	m_texture.loadFromFile("data/enemy.png");

}

void EnemyPool::update(float dt, Application *app, Map &map)
{
	sf::Time timer = clock.getElapsedTime();
	if (timer.asSeconds() > 5) {
		enemies.push_back(Enemy());
		enemies.back().initialize(map, m_texture);
		clock.restart();
	}

	for (int i = 0; i < enemies.size(); i++) {
		enemies[i].update(dt, map);
        if(enemies[i].getHealth() <= 0)
        {
            enemies[i].release();
            enemies.erase(enemies.begin() + i);
        }
	}
}

void EnemyPool::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i].draw(window);
	}
}

