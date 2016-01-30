#include "Ritual.h"
Ritual::Ritual()
{
}

Ritual::~Ritual()
{

}

void Ritual::initialize(Map &map)
{ 
	for (int i = 0; i < 5; i++) {
		m_personTexture[i].loadFromFile("data/Stickman.png");
		m_personSprite[i].setTexture(m_personTexture[i]);
		//m_personSprite[i].setOrigin(getXLoc(i) + map.getWidth() / 2, getYloc(i) + map.getHeight() / 2);
		m_personSprite[i].setPosition((getXLoc(i) + map.getWidth() / 2) - (m_personSprite[i].getLocalBounds().width / 2),
										(getYloc(i) + map.getHeight() / 2) - (m_personSprite[i].getLocalBounds().height / 2));
	}

	m_fireTexture.loadFromFile("data/fire.png");
	m_fireSprite.setTexture(m_fireTexture);
	//m_fireSprite.setOrigin(map.getWidth() / 2, map.getHeight() / 2);
	m_fireSprite.setPosition((map.getWidth() / 2) - (m_fireSprite.getLocalBounds().width / 2), 
								(map.getHeight() / 2) - (m_fireSprite.getLocalBounds().height /2));
}

void Ritual::release()
{
}

void Ritual::update(float dt)
{
}

void Ritual::draw(sf::RenderWindow &window)
{
	window.draw(m_fireSprite);
	for (int i = 0; i < 5; i++) {
		window.draw(m_personSprite[i]);
	}
}


int Ritual::getXLoc(int n) 
{
	return cosf(n*1.2566370614359172953850573533118) * radius;
}

int Ritual::getYloc(int n)
{
	return sinf(n*1.2566370614359172953850573533118) * radius;
}
