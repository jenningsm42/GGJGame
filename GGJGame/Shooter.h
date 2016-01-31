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
	virtual void update(float dt) override;
	virtual void draw(sf::RenderWindow &) override;
};

#endif
