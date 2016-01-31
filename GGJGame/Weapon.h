#ifndef WEAPON_H
#define WEAPON_H

#include <SFML/Graphics.hpp>
#include "Map.h"
#include "GameObject.h"
#include "Weapontypes.h"

class Weapon : public GameObject
{
public:
	void Weapon::initialize(Map &, float x, float y);
protected:
	weapontype m_type;
};
#endif