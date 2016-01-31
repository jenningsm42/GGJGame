#include "WeaponPool.h"
#include <SFML/Graphics.hpp>

WeaponPool::WeaponPool()
{
}

WeaponPool::~WeaponPool()
{
}

void WeaponPool::initialize(Map &, Application *)
{
	//m_texture[0].loadFromFile("data/energy_shooter");
}

void WeaponPool::placeWeapon(weapontype type, float x, float y, Map &map)
{
	switch (type) {
	case(weapontype::shooter) : {
		weapons.push_back(Shooter());
		weapons.back().initialize(map, x, y);
	}
	}
}

void WeaponPool::update(float dt, Application *, Map & map)
{
}

void WeaponPool::draw(sf::RenderWindow &)
{

}
