#ifndef ENEMY_H
#define ENEMY_H
#include "GameObject.h"
#include "Map.h"
#include <SFML/Graphics.hpp>

class Enemy : public GameObject
{
public:
	virtual void initialize(Map& map, sf::Texture &m_texture) {}
	virtual	void release() {}

	virtual void update(float dt, Map &map) {}
	virtual void draw(sf::RenderWindow&) {}

	const sf::FloatRect getBounds() const;
	const sf::Vector2f getCenter() const;

	void damage();
	int getHealth();

	void damageOverTime();
	void slow();

protected:
	int m_health;
	float m_speed;
	int DotDuration = 0;
	int slowDuration = 0;
};
#endif