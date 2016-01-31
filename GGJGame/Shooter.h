#ifndef SHOOTER_H
#define SHOOTER_H
#include "Weapon.h"

class Shooter : public Weapon
{
public: 
	Shooter();
	~Shooter();

    void initialize(Map &, float x, float y, sf::Texture&) override;
	virtual void release() override;
	virtual void update(float dt, EnemyPool&, ProjectilePool&) override;
	virtual void draw(sf::RenderWindow &) override;
    
private:
    float m_rangeSq = 300.f*300.f;
    float m_delay = 2.f; // In seconds
};

#endif
