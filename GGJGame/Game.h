#ifndef GAME_H
#define GAME_H
#include "State.h"
#include "Map.h"
#include "Ritual.h"
#include "Worker.h"


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
    Worker m_workers[10];
    int m_workerCount;
};

#endif // GAME_H