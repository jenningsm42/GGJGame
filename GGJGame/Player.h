#ifndef PLAYER_H
#define PLAYER_H
#include "GameObject.h"

class Player : public GameObject
{
public:
	void initialize() override;
	void release() override;

	void update(float dt, Application*) override;
	void draw(sf::RenderWindow&) override;

private:
	const float m_speed = 350.f;
};

#endif // PLAYER_H