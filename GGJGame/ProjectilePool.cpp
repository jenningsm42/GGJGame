#include "ProjectilePool.h"

ProjectilePool::ProjectilePool()
{
    m_projectileTexture[0].loadFromFile("data/projectile.png");
	m_projectileTexture[1].loadFromFile("data/acid.png");
}

ProjectilePool::~ProjectilePool()
{
}

void ProjectilePool::spawnProjectile(float x, float y, Enemy *target, ProjectileType type)
{
	switch (type) {
	case ProjectileType::Energy:
            m_projectiles.push_back(Projectile(m_projectileTexture[0], sf::Vector2f(x, y), target));
            break;
	case ProjectileType::Acid:
            m_projectiles.push_back(Projectile(m_projectileTexture[1], sf::Vector2f(x, y), target));
            break;
	}
    
}

void ProjectilePool::update(float dt)
{
    for(int i = 0; i < m_projectiles.size(); i++)
    {
        if(m_projectiles[i].update(dt))
        {
            // projectile hit target
            m_projectiles.erase(m_projectiles.begin() + i);
        }
    }
}

void ProjectilePool::draw(sf::RenderWindow& window)
{
    for(int i = 0; i < m_projectiles.size(); i++)
        m_projectiles[i].draw(window);
}