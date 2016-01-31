#ifndef TOTEM_H
#define TOTEM_H
#include "Weapon.h"

class Totem : public Weapon
{
public:
	Totem();
	~Totem();

	void initialize(Map &, float x, float y, sf::Texture&) override;
	virtual void release() override;
	virtual void update(float dt, EnemyPool&, ProjectilePool&) override;
	virtual void draw(sf::RenderWindow &) override;

private:
    sf::Clock m_timer;
	float m_rangeSq = 450.f*450.f;
	float m_delay = 3.5f; // In seconds
};

#endif
