#ifndef Tower_H
#define Tower_H
#include "Weapon.h"

class Tower : public Weapon
{
public:
	Tower();
	~Tower();

	void initialize(Map &, float x, float y, sf::Texture&) override;
	virtual void release() override;
	virtual void update(float dt, EnemyPool&, ProjectilePool&) override;
	virtual void draw(sf::RenderWindow &) override;

private:
    sf::Clock m_timer;
	float m_rangeSq = 600.f*600.f;
	float m_delay = 4.f; // In seconds
};

#endif
