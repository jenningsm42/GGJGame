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
    
    void setTarget(sf::Vector2f target);
    void assignRitualist(int index);
    int getAssignedRitualist();

	void damage(int amount);
	int getHealth();

	void damageOverTime(int damage);
	void slow();

protected:
    sf::Vector2f m_target;
    int m_ritualist = -1;
	int m_health;
	float m_speed;
	int DotDuration = 0;
    int m_dotDamage = 0;
	int slowDuration = 0;
};

#endif