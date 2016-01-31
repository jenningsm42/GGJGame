#pragma once
#include "Map.h"
#include "EnemyPool.h"

class Ritual 
{
public:
	Ritual();
	~Ritual();

	void initialize(Map &);
	void release();

	bool update(float dt, EnemyPool&);
	void draw(sf::RenderWindow &);
    
    bool isAlive(int index);
    sf::Vector2f getCenter(int index);
	
private:
	sf::Texture m_personTexture;
	sf::Sprite m_personSprite[5];
	sf::Texture m_fireTexture;
	sf::Sprite m_fireSprite;
    sf::Texture m_logTexture;
    sf::Sprite m_logSprite;
    sf::Texture m_chiefTexture;
    sf::Sprite m_chiefSprite;
    int m_ritualistCount;
    bool m_ritualistsAlive[5];
    const float m_radius;
    float m_angle;
    float m_offsetX;
    float m_offsetY;
    
    int getXLoc(int n);
    int getYloc(int n);
};



