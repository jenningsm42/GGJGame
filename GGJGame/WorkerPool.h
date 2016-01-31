#ifndef WORKERPOOL_H
#define WORKERPOOL_H
#include <SFML/Graphics.hpp>
#include "Worker.h"
#include "Map.h"
#include "WeaponsUI.h"
#include "WeaponTypes.h"
#include "EnemyPool.h"
#include "Currency.h"
#include "Announcements.h"
class Application;

class WorkerPool
{
public:
    WorkerPool();
    ~WorkerPool();
    
    void initialize(Map&, Application*);
    
    void update(float dt, Application* app, Map& map, WeaponPool&, EnemyPool&, Currency&, Announcements&);
    void draw(sf::RenderWindow&);
    
private:
    Worker m_workers[10];
    WeaponsUI m_weaponsUI;
    int m_workerCount;
    int m_selectedWorker;
    sf::Texture m_selectedTexture;
    sf::Sprite m_selectedSprite;
    WeaponType m_placingWeaponType;
    
    bool validMove(float x, float y, Map&);
};

#endif // WORKERPOOL_H
