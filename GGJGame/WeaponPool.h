#pragma once
#include <SFML/Graphics.hpp>
#include "Worker.h"
#include "Map.h"
#include "WeaponsUI.h"
#include "Weapontypes.h"
#include "Shooter.h"

class WeaponPool
{
public:
	WeaponPool();
	~WeaponPool();

	void initialize(Map&, Application*);
	void update(float dt, Application*, Map& map);
	void draw(sf::RenderWindow&);

private 
};