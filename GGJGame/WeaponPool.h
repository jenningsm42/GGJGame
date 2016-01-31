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
	void placeWeapon(weapontype type, float x, float y, Map &);
	void update(float dt, Application*, Map& map);
	void draw(sf::RenderWindow&);

private:
		sf::Texture m_texture[1];
		std::vector<Weapon> weapons;
};