#ifndef PROJECTILEPOOL_H
#define PROJECTILEPOOL_H
#include <vector>
#include "Projectile.h"
#include "ProjectileType.h"

class ProjectilePool
{
public:
    ProjectilePool();
    ~ProjectilePool();
    
    void spawnProjectile(float x, float y, Enemy* target, projectileType type);
    void update(float dt);
    void draw(sf::RenderWindow&);
    
private:
    sf::Texture m_projectileTexture[2];
    std::vector<Projectile> m_projectiles;
};

#endif // PROJECTILEPOOL_H
