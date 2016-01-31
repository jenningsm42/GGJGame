#pragma once
#include "GameObject.h"
#include "Map.h"
#include "EnemyPool.h"

class Ritual : public GameObject 
{
public:
	Ritual();
	~Ritual();

	void initialize(Map &);
	virtual void release() override;

    bool update(float dt, EnemyPool&);
	virtual void draw(sf::RenderWindow &) override;
    
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
    sf::SoundBuffer fireSound;
    sf::SoundBuffer tribalSound;
    int m_ritualistCount;
    bool m_ritualistsAlive[5];
    const float m_radius;
    float m_angle;
    float m_offsetX;
    float m_offsetY;
    
    int getXLoc(int n);
    int getYloc(int n);
};



