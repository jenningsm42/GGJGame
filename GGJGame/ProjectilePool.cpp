#include "ProjectilePool.h"

ProjectilePool::ProjectilePool()
{
    m_projectileTexture.loadFromFile("data/projectile.png");
}

ProjectilePool::~ProjectilePool()
{
}

void ProjectilePool::spawnProjectile(float x, float y, Enemy *target)
{
    m_projectiles.push_back(Projectile(m_projectileTexture, sf::Vector2f(x, y), target));
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