#include "Ritual.h"
#include <cmath>

Ritual::Ritual() : m_radius(100.f), m_angle(0.f)
{
}

Ritual::~Ritual()
{

}

void Ritual::initialize(Map &map)
{
    m_offsetX = map.getWidth() / 2;
    m_offsetY = map.getHeight() / 2;
    
    m_personTexture.loadFromFile("data/ritualist.png");
    
	for (int i = 0; i < 5; i++) {
        m_personSprite[i].setTexture(m_personTexture);
        m_personSprite[i].setOrigin(m_personTexture.getSize().x / 2, m_personTexture.getSize().y / 2);
		m_personSprite[i].setPosition(getXLoc(i) + m_offsetX, getYloc(i) + m_offsetY);
	}

	m_fireTexture.loadFromFile("data/fire.png");
	m_fireSprite.setTexture(m_fireTexture);
	m_fireSprite.setPosition(m_offsetX - (m_fireSprite.getLocalBounds().width / 2),
								m_offsetY - (m_fireSprite.getLocalBounds().height /2));
    
    m_logTexture.loadFromFile("data/log.png");
    m_logSprite.setTexture(m_logTexture);
    m_logSprite.setPosition(m_offsetX - (m_logTexture.getSize().x / 2), m_offsetY + 10);
    
    m_chiefTexture.loadFromFile("data/chief.png");
    m_chiefSprite.setTexture(m_chiefTexture);
    m_chiefSprite.setPosition(m_offsetX - m_chiefTexture.getSize().x / 2,
                              m_offsetY - m_radius - 150);
}

void Ritual::release()
{
}

void Ritual::update(float dt)
{
    m_angle += dt * .5f;
    
    float fireFactor = sinf(m_angle * .8f) / 2.f + .5f;
    m_fireSprite.setColor(sf::Color(60 * fireFactor + 180, 90 * fireFactor + 100, 200 * (1.f - fireFactor) + 10));
    
    for(int i = 0; i < 5; i++)
    {
        m_personSprite[i].setPosition(getXLoc(i) + m_offsetX, getYloc(i) + m_offsetY);
        
        if(int(m_angle * 100.f) % 50 > 25)
            m_personSprite[i].setScale(-1.f, 1.f);
        else
            m_personSprite[i].setScale(1.f, 1.f);
    }
}

void Ritual::draw(sf::RenderWindow &window)
{
    window.draw(m_chiefSprite);
    window.draw(m_logSprite);
	window.draw(m_fireSprite);
	for (int i = 0; i < 5; i++) {
		window.draw(m_personSprite[i]);
	}
}


int Ritual::getXLoc(int n) 
{
	return cosf(n*1.256637f + m_angle) * m_radius;
}

int Ritual::getYloc(int n)
{
	return sinf(n*1.256637f + m_angle) * m_radius;
}
