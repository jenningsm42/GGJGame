#ifndef GAME_H
#define GAME_H
#include "State.h"
#include "Map.h"
#include "Ritual.h"
#include "WorkerPool.h"
#include "EnemyPool.h"
#include "ProjectilePool.h"
#include "Currency.h"
#include "Announcements.h"
#include "GameOver.h"
#include <SFML/Audio.hpp>

class Game : public State
{
public:
	Game();
	~Game();

	void initialize(Application*) override;
	void release() override;

	void update(float dt, Application*) override;
	void draw(sf::RenderWindow& window) override;

private:
    sf::Music m_ambience;
    sf::Music m_bg;
    Map m_map;
	Ritual m_ritual;
    WorkerPool m_workerPool;
	EnemyPool m_enemyPool;
	WeaponPool m_weaponPool;
    ProjectilePool m_projectilePool;
    Currency m_currency;
    Announcements m_announcements;
    GameOver m_gameOver;
    bool m_isGameOver;
};

#endif // GAME_H