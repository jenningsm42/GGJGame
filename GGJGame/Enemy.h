#ifndef ENEMY_H
#define ENEMY_H
#include "GameObject.h"
#include "Map.h"
#include <iostream>

class Enemy : public GameObject
{
public:
	Enemy();
	~Enemy();

	void initialize(Map& map, sf::Texture &m_texture);
	void release() override;

	void update(float dt, Map &map);
	void draw(sf::RenderWindow&) override;

	const sf::FloatRect getBounds() const;
	const sf::Vector2f getCenter() const;
};

#endif // ENEMY_H