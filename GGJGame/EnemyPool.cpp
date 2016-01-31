#include "EnemyPool.h"
#include "Application.h"
#include "Ghost.h"
#include "Zombie.h"
#include "Ritual.h"
#include "Bar.h"
#include <string>
#include <cmath>

EnemyPool::EnemyPool() : m_spawnRate(1.f)
{
}

EnemyPool::~EnemyPool()
{
}

void EnemyPool::initialize(Map &)
{
	m_enemyTextures[0].loadFromFile("data/zombie.png");
	m_enemyTextures[1].loadFromFile("data/ghost.png");
    m_zombieDeathBuf.loadFromFile("data/tribal_3_bip.wav");
    m_ghostDeathBuf.loadFromFile("data/Tribal_2_bip.wav");
    m_zdSound.setBuffer(m_zombieDeathBuf);
    m_gdSound.setBuffer(m_ghostDeathBuf);
}

void EnemyPool::update(float dt, Application *app, Map &map, Currency& currency, Announcements& announcements, Ritual* ritual)
{
	if (m_waveClock.getElapsedTime().asSeconds() > 3.f && !m_inWave) {//todo
        m_inWave = true;
        m_waveClock.restart();
        m_spawnRate = expf(-.55 * (float)m_waveCount);
        m_waveCount++;
        
        if(m_bg.getStatus() != sf::Sound::Playing && m_bg.openFromFile("data/Spirit_Defense_Music_fade.wav")) {
            m_bg.setVolume(80);
            m_bg.play();
        }
        
        announcements.setAnnouncement("Wave  " + std::to_string(m_waveCount) + "  starting..");
    }
    
    if(m_inWave)
    {
        if(m_waveClock.getElapsedTime().asSeconds() > 60.f && m_enemies.size() == 0)
        {
            m_inWave = false;
            m_waveClock.restart();
            announcements.setAnnouncement("Wave  " + std::to_string(m_waveCount) + "  finished!");
        }
        
        if(m_waveClock.getElapsedTime().asSeconds() <= 60.f)
        {
            if (m_zombieClock.getElapsedTime().asSeconds() > 5.f * m_spawnRate) {
                m_enemies.push_back(new Zombie());
                m_enemies.back()->initialize(map, m_enemyTextures[0]);
                m_enemies.back()->setTarget(sf::Vector2f(map.getWidth() / 2, map.getHeight() / 2));
                
                m_bars.push_back(new Bar(m_enemies.back()->getHealth()));
                m_bars.back()->setCurrentValue(m_enemies.back()->getHealth());
                
                m_zombieClock.restart();
            }
            if (m_waveCount >= 2 && m_ghostClock.getElapsedTime().asSeconds() > 15.f * m_spawnRate) {
                m_enemies.push_back(new Ghost());
                m_enemies.back()->initialize(map, m_enemyTextures[1]);
                m_enemies.back()->setTarget(sf::Vector2f(map.getWidth() / 2, map.getHeight() / 2));
                
                m_bars.push_back(new Bar(m_enemies.back()->getHealth()));
                m_bars.back()->setCurrentValue(m_enemies.back()->getHealth());
                
                m_ghostClock.restart();
            }
        }
        
        for (int i = 0; i < m_enemies.size(); i++) {
            m_enemies[i]->update(dt, map);
            m_bars[i]->setCurrentValue(m_enemies[i]->getHealth());
            m_bars[i]->update(m_enemies[i]->getCenter());
            
            if(m_enemies[i]->getHealth() <= 0)
            {
                currency.addCurrency(25);
                
                switch(m_enemies[i]->getType())
                {
                    case 0: m_zdSound.play(); break;
                    case 1: m_gdSound.play(); break;
                }
                
                m_enemies[i]->release();
                delete m_enemies[i];
                m_enemies.erase(m_enemies.begin() + i);
                
                delete m_bars[i];
                m_bars.erase(m_bars.begin() + i);
            }
            
            float dx = map.getWidth() / 2 - m_enemies[i]->getCenter().x;
            float dy = map.getHeight() / 2 - m_enemies[i]->getCenter().y;
            float dist = dx*dx + dy*dy;
            
            if(dist < 800.f*800.f)
            {
                if(m_enemies[i]->getAssignedRitualist() == -1 || !ritual->isAlive(m_enemies[i]->getAssignedRitualist()))
                {
                    for(int j = 0; j < 5; j++)
                    {
                        if(ritual->isAlive(j))
                        {
                            m_enemies[i]->assignRitualist(j);
                            m_enemies[i]->setTarget(ritual->getCenter(j));
                        }
                    }
                } else m_enemies[i]->setTarget(ritual->getCenter(m_enemies[i]->getAssignedRitualist()));
            }
        }
    }
}

void EnemyPool::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < m_enemies.size(); i++) {
		m_enemies[i]->draw(window);
	}
    for(int i = 0; i < m_bars.size(); i++)
    {
        m_bars[i]->draw(window);
    }
}

int EnemyPool::size()
{
    return m_enemies.size();
}

Enemy& EnemyPool::getEnemy(int index)
{
    return *m_enemies[index];
}