#ifndef WEAPON_H
#define WEAPON_H
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "GameObject.h"
#include "WeaponTypes.h"

class Weapon : public GameObject
{
public:
    virtual void initialize(Map &, float x, float y, sf::Texture&) {}
protected:
	WeaponType m_type;
};

#endif