#include "EnemyPool.h"
#include "Application.h"
#include "Ghost.h"
#include "Zombie.h"
#include <string>

EnemyPool::EnemyPool()
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

void EnemyPool::update(float dt, Application *app, Map &map, Currency& currency, Announcements& announcements)
{
	if (m_waveClock.getElapsedTime().asSeconds() > 30.f && !m_inWave) {
        m_inWave = true;
        m_waveClock.restart();
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
            if (m_zombieClock.getElapsedTime().asSeconds() > 5.f) {
                m_enemies.push_back(new Zombie());
                m_enemies.back()->initialize(map, m_enemyTextures[0]);
                m_zombieClock.restart();
            }
            if (m_ghostClock.getElapsedTime().asSeconds() > 15.f && m_waveCount >= 2) {
                m_enemies.push_back(new Ghost());
                m_enemies.back()->initialize(map, m_enemyTextures[1]);
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