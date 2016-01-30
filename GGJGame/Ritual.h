#pragma once
#include "GameObject.h"
#include "Map.h"
#include <vector>
#include <cstdlib>
#include <math.h>
class Ritual : public GameObject 
{
public:
	Ritual();
	~Ritual();

	// Inherited via GameObject
	void initialize(Map &);

	virtual void release() override;

	virtual void update(float dt) override;

	virtual void draw(sf::RenderWindow &) override;
	
private:

	sf::Texture m_personTexture[5];
	sf::Sprite m_personSprite[5];
	sf::Texture m_fireTexture;
	sf::Sprite m_fireSprite;
	int getXLoc(int n);
	int getYloc(int n);
	const int radius = 100;
};


