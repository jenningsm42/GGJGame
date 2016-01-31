#ifndef WEAPONPOOL_H
#define WEAPONPOOL_H
#include <SFML/Graphics.hpp>
#include "Weapon.h"
#include "Shooter.h"
#include "Totem.h"


class WeaponPool
{
public:
	WeaponPool();
	~WeaponPool();

	void initialize(Map&, Application*);
	void placeWeapon(WeaponType type, float x, float y, Map &);
	void update(float dt, Application*, Map& map, EnemyPool&, ProjectilePool&);
	void draw(sf::RenderWindow&);

private:
	sf::Texture m_texture[2];
	std::vector<Weapon*> weapons;
};

#endif // WEAPONPOOL_H