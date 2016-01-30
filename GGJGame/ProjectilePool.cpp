#include "ProjectilePool.h"

ProjectilePool::ProjectilePool()
{
    m_projectileTexture.loadFromFile("data/projectile.png");
}

ProjectilePool::~ProjectilePool()
{
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