#ifndef ENEMYPOOL_H
#define ENEMYPOOL_H
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Currency.h"
#include "Announcements.h"
#include "Enemy.h"
#include "GameObject.h"
class Application;
class Ritual;
class Bar;

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
    sf::Clock m_waveClock;
    sf::Music m_bg;
    sf::SoundBuffer m_zombieDeathBuf;
    sf::SoundBuffer m_ghostDeathBuf;
    sf::Sound m_zdSound;
    sf::Sound m_gdSound;
	int m_enemyCount = 0;
    int m_waveCount = 0;
    bool m_inWave = false;
    float m_spawnRate;
	std::vector<Enemy*> m_enemies;
    std::vector<Bar*> m_bars;
	sf::Texture m_enemyTextures[2];
};

#endif
