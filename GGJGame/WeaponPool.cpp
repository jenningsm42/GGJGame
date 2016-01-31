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
	m_texture[1].loadFromFile("data/Totem.png");
}

void WeaponPool::placeWeapon(WeaponType type, float x, float y, Map &map)
{
	switch (type) {
        case WeaponType::Shooter: {
            weapons.push_back(new Shooter());
            weapons.back()->initialize(map, x, y, m_texture[0]);
        } break;
		case WeaponType::Acid: {
			weapons.push_back(new Totem());
			weapons.back()->initialize(map, x, y, m_texture[1]);
		}
        default: break;
	}
}

void WeaponPool::update(float dt, Application*, Map & map, EnemyPool& enemyPool, ProjectilePool& projectilePool)
{
    for(int i = 0; i < weapons.size(); i++)
        weapons[i]->update(dt, enemyPool, projectilePool);
}

void WeaponPool::draw(sf::RenderWindow& window)
{
    for(int i = 0; i < weapons.size(); i++)
        weapons[i]->draw(window);
}
