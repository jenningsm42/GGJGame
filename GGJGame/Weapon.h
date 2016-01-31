#ifndef WEAPON_H
#define WEAPON_H

#include <SFML/Graphics.hpp>
#include "Map.h"
#include "GameObject.h"
#include "Weapontypes.h"

class Weapon : public GameObject
{
protected:
	weapontype m_type;
};
#endif