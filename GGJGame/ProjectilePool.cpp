#include "ProjectilePool.h"

ProjectilePool::ProjectilePool()
{
    m_projectileTexture[0].loadFromFile("data/projectile.png");
	m_projectileTexture[1].loadFromFile("data/acid.png");
    m_projectileTexture[2].loadFromFile("data/dart.png");
    energy.loadFromFile("data/energy_projectile_bip.wav");
    acid.loadFromFile("data/Quicksand_sound_bip.wav");
    dart.loadFromFile("data/Blowdart_projectile_bip.wav");
    eSound.setBuffer(energy);
    aSound.setBuffer(acid);
    dSound.setBuffer(dart);
}

ProjectilePool::~ProjectilePool()
{
}

void ProjectilePool::spawnProjectile(float x, float y, Enemy *target, ProjectileType type)
{
	switch (type) {
	case ProjectileType::Energy: {
		m_projectiles.push_back(new Projectile(m_projectileTexture[0], sf::Vector2f(x, y), target, type));
		eSound.play();
		break; 
	}
	case ProjectileType::Acid: {
		m_projectiles.push_back(new Projectile(m_projectileTexture[1], sf::Vector2f(x, y), target, type));
		aSound.play();
		break;
	}
	case ProjectileType::Dart: {
		m_projectiles.push_back(new Projectile(m_projectileTexture[2], sf::Vector2f(x, y), target, type));
		dSound.play();
		break;
	}
	}
}

void ProjectilePool::update(float dt)
{
    for(int i = 0; i < m_projectiles.size(); i++)
    {
        if(m_projectiles[i]->update(dt))
        {
            // projectile hit target
            delete m_projectiles[i];
            m_projectiles.erase(m_projectiles.begin() + i);
        }
    }
}

void ProjectilePool::draw(sf::RenderWindow& window)
{
    for(int i = 0; i < m_projectiles.size(); i++)
        m_projectiles[i]->draw(window);
}