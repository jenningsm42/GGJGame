#ifndef GAME_H
#define GAME_H
#include "State.h"
#include "Player.h"

class Game : public State
{
public:
	Game();
	~Game();

	void initialize() override;
	void release() override;

	void update(float dt) override;
	void draw(sf::RenderWindow& window) override;

private:
	Player m_player;
};

#endif // GAME_H