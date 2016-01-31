#ifndef GAME_H
#define GAME_H
#include "State.h"
#include "Map.h"
#include "Ritual.h"
#include "WorkerPool.h"
#include "EnemyPool.h"

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
    Map m_map;
	Ritual m_ritual;
    WorkerPool m_workerPool;
	EnemyPool m_enemyPool;
	WeaponPool m_weaponPool;
};

#endif // GAME_H