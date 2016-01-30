#ifndef WEAPONOBJECTS_H
#define WEAPONOBJECTS_H
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Map.h"


class Shooter : public Weapon
{
public: 
	Shooter();
	~Shooter();

	void initialize(Map &);

	virtual void release() override;

	virtual void update(float dt) override;

	virtual void draw(sf::RenderWindow &) override;

private: 
	sf::Texture m_Texture();
	sf::Sprite m_Sprite();
};
#endif
