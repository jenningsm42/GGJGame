#ifndef ENEMYPOOL_H
#define ENEMYPOOL_H
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Currency.h"
#include "Announcements.h"
#include "Enemy.h"
#include "BossGhost.h"
#include "GameObject.h"
#include "Application.h"
#include "Ghost.h"
#include "Zombie.h"
#include "Ritual.h"
#include <string>
#include <cmath>
class Application;
class Ritual;

class EnemyPool
{
public:
	EnemyPool();
	~EnemyPool();

	void initialize(Map&);
	void update(float dt, Application*, Map&, Currency&, Announcements&, Ritual*);
	void draw(sf::RenderWindow&);
    
    int size();
    Enemy& getEnemy(int index);
    
private:
	sf::Clock m_zombieClock;
	sf::Clock m_ghostClock;
	sf::Clock m_bossClock;
	sf::Clock m_waveClock;
	int m_enemyCount = 0;
    int m_waveCount = 0;
    bool m_inWave = false;
    float m_spawnRate;
	std::vector<Enemy*> m_enemies;
	sf::Texture m_enemyTextures[3];
};

#endif
