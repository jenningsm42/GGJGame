#include "Ritual.h"
Ritual::Ritual()
{
}

void Ritual::initialize(Map &map)
{ 
	for (int i = 0; i < personNumber; i++) {
		m_personTexture[i].loadFromFile("data/Stickman.png");
		m_personSprite.setTexture(m_personTexture[i]);
		m_personSprite.setPosition(getRandomLocation(), getRandomLocation());
	}
	m_fireTexture.loadFromFile("data/fire.png");
	m_fireSprite.setTexture(m_fireTexture);
	m_fireSprite.setPosition(map.getWidth() / 2, map.getHeight() / 2);
}

void Ritual::release()
{
}

void Ritual::update(float dt, Application *)
{
}

void Ritual::draw(sf::RenderWindow &window)
{
	window.draw(m_fireSprite);
	for (int i = 0; i < personNumber; i++) {
		window.draw(m_personSprite);
	}
}


int Ritual::getRandomLocation() 
{
	const int radius = 70; 
	int temp = rand() % 100;
	int x = sin(temp) * 70;
	return x;
}
