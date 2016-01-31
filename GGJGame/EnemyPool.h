#ifndef ENEMYPOOL_H
#define ENEMYPOOL_H
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Enemy.h"
#include "GameObject.h"
class Application;

class EnemyPool
{
public:
	EnemyPool();
	~EnemyPool();

	void initialize(Map&);
	void update(float dt, Application*, Map&);
	void draw(sf::RenderWindow&);

private:
	sf::Clock zombieClock;
	sf::Clock ghostClock;
	sf::Clock initialClock;
	int Enemycount = 0;
	std::vector<Enemy*> enemies;
	sf::Texture m_enemyTextures[2];

};

#endif
