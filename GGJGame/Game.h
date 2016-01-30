#ifndef GAME_H
#define GAME_H
#include "State.h"
#include "Map.h"

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
};

#endif // GAME_H