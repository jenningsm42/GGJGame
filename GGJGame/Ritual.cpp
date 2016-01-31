#include "Ritual.h"
#include <cmath>

Ritual::Ritual() : m_radius(100.f), m_angle(0.f), m_ritualistCount(5)
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
        m_ritualistsAlive[i] = true;
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

	//For sound:
	fireSound.loadFromFile("data/Fire_sound_bip.wav");
	sf::Sound sound;
	sound.setBuffer(fireSound);
	sound.setVolume(75);
	sound.setLoop(true);
	sound.play();

	tribalSound.loadFromFile("data/Tribal_Chantss_bip.wav");
	sf::Sound tribe;
	tribe.setBuffer(tribalSound);
	tribe.setPlayingOffset(sf::seconds(5));
	tribe.play();
}

void Ritual::release()
{
}

bool Ritual::update(float dt, EnemyPool& enemyPool)
{
    m_angle += dt * .4f;
    
    float fireFactor = sinf(m_angle * .8f) / 2.f + .5f;
    m_fireSprite.setColor(sf::Color(60 * fireFactor + 180, 90 * fireFactor + 100, 200 * (1.f - fireFactor) + 10));
    
    for(int i = 0; i < 5; i++)
    {
        if(!m_ritualistsAlive[i]) continue;
        
        for(int j = 0; j < enemyPool.size(); j++)
        {
            sf::Vector2f epos = enemyPool.getEnemy(j).getCenter();
            float dx = epos.x - m_personSprite[i].getPosition().x;
            float dy = epos.y - m_personSprite[i].getPosition().y;
            float dist = dx*dx + dy*dy;
            
            if(dist < 4000.f)
            {
                m_ritualistsAlive[i] = false;
                enemyPool.getEnemy(j).damage(enemyPool.getEnemy(j).getHealth());
                m_ritualistCount--;
                if(m_ritualistCount <= 0)
                    return true; // Game over
            }
        }
        
        m_personSprite[i].setPosition(getXLoc(i) + m_offsetX, getYloc(i) + m_offsetY);
        
        if(int(m_angle * 100.f) % 50 > 25)
            m_personSprite[i].setScale(-1.f, 1.f);
        else
            m_personSprite[i].setScale(1.f, 1.f);
    }
    
    return false;
}

void Ritual::draw(sf::RenderWindow &window)
{
    window.draw(m_chiefSprite);
    window.draw(m_logSprite);
	window.draw(m_fireSprite);
	for (int i = 0; i < 5; i++) {
		if(m_ritualistsAlive[i])
            window.draw(m_personSprite[i]);
	}
}


int Ritual::getXLoc(int n) 
{
	return cosf((float)n * 3.14159f * 2.f / 5.f + m_angle) * m_radius;
}

int Ritual::getYloc(int n)
{
	return sinf((float)n * 3.14159f * 2.f / 5.f + m_angle) * m_radius;
}

bool Ritual::isAlive(int index)
{
    if(index == -1) return false;
    return m_ritualistsAlive[index];
}

sf::Vector2f Ritual::getCenter(int index)
{
    return m_personSprite[index].getPosition()
    + .5f * sf::Vector2f(m_personSprite[index].getLocalBounds().width, m_personSprite[index].getLocalBounds().height);
}
