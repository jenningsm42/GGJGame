#include "EnemyPool.h"
#include "Application.h"
#include "Ghost.h"
#include "Zombie.h"
#include "Ritual.h"
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
}

void EnemyPool::update(float dt, Application *app, Map &map, Currency& currency, Announcements& announcements, Ritual* ritual)
{
	if (m_waveClock.getElapsedTime().asSeconds() > 3.f && !m_inWave) {//todo
        m_inWave = true;
        m_waveClock.restart();
        m_spawnRate = expf(-.55 * (float)m_waveCount);
        m_waveCount++;
        
        announcements.setAnnouncement("Wave  " + std::to_string(m_waveCount) + "  starting..");
    }
    
    if(m_inWave)
    {
        if(m_waveClock.getElapsedTime().asSeconds() > 60.f && m_enemies.size() == 0)
        {
            m_inWave = false;
            m_waveClock.restart();
        }
        
        if(m_waveClock.getElapsedTime().asSeconds() <= 60.f)
        {
            if (m_zombieClock.getElapsedTime().asSeconds() > 5.f * m_spawnRate) {
                m_enemies.push_back(new Zombie());
                m_enemies.back()->initialize(map, m_enemyTextures[0]);
                m_enemies.back()->setTarget(sf::Vector2f(map.getWidth() / 2, map.getHeight() / 2));
                m_zombieClock.restart();
            }
            if (m_waveCount >= 2 && m_ghostClock.getElapsedTime().asSeconds() > 15.f * m_spawnRate) {
                m_enemies.push_back(new Ghost());
                m_enemies.back()->initialize(map, m_enemyTextures[1]);
                m_enemies.back()->setTarget(sf::Vector2f(map.getWidth() / 2, map.getHeight() / 2));
                m_ghostClock.restart();
            }
        }
        
        for (int i = 0; i < m_enemies.size(); i++) {
            m_enemies[i]->update(dt, map);
            
            if(m_enemies[i]->getHealth() <= 0)
            {
                currency.addCurrency(25);
                m_enemies[i]->release();
                m_enemies.erase(m_enemies.begin() + i);
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
}

int EnemyPool::size()
{
    return m_enemies.size();
}

Enemy& EnemyPool::getEnemy(int index)
{
    return *m_enemies[index];
}