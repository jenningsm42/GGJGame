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
	m_texture[0].loadFromFile("data/energy_shooter.png");
}

void WeaponPool::placeWeapon(WeaponType type, float x, float y, Map &map)
{
	switch (type) {
        case WeaponType::Shooter: {
            weapons.push_back(new Shooter());
            weapons.back()->initialize(map, x, y, m_texture[0]);
        } break;
        default: break;
	}
}

void WeaponPool::update(float dt, Application *, Map & map)
{
    for(int i = 0; i < weapons.size(); i++)
        weapons[i]->update(dt);
}

void WeaponPool::draw(sf::RenderWindow& window)
{
    for(int i = 0; i < weapons.size(); i++)
        weapons[i]->draw(window);
}
