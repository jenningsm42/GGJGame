#ifndef PROJECTILEPOOL_H
#define PROJECTILEPOOL_H
#include <vector>
#include "Projectile.h"

class ProjectilePool
{
public:
    ProjectilePool();
    ~ProjectilePool();
    
    void update(float dt);
    
private:
    sf::Texture m_projectileTexture;
    std::vector<Projectile> m_projectiles;
};

#endif // PROJECTILEPOOL_H
