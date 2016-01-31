#ifndef PROJECTILEPOOL_H
#define PROJECTILEPOOL_H
#include <vector>
#include "Projectile.h"
#include <SFML/Audio.hpp>
#include "ProjectileType.h"

class ProjectilePool
{
public:
    ProjectilePool();
    ~ProjectilePool();
    
    void spawnProjectile(float x, float y, Enemy* target, ProjectileType type);
    void update(float dt);
    void draw(sf::RenderWindow&);
    
private:
    sf::Texture m_projectileTexture[3];
    std::vector<Projectile*> m_projectiles;
    sf::SoundBuffer energy;
    sf::SoundBuffer acid;
    sf::SoundBuffer dart;
    sf::Sound eSound;
    sf::Sound aSound;
    sf::Sound dSound;
};

#endif // PROJECTILEPOOL_H
