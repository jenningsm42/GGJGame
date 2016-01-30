#ifndef ENEMY_H
#define ENEMY_H
#include "GameObject.h"
#include "Map.h"
#include <iostream>
#include "Command.h"

class Enemy : public GameObject
{
public:
	Enemy();
	~Enemy();

	void initialize(Map& map, sf::Texture &m_texture);
	void release() override;

	void update(float dt, Map &map);
	void draw(sf::RenderWindow&) override;
    
    void damage();
    int getHealth();

	const sf::FloatRect getBounds() const;
	const sf::Vector2f getCenter() const;
    
private:
    int m_health;
	const float m_speed;
};

#endif // ENEMY_H