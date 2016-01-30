#ifndef WORKERPOOL_H
#define WORKERPOOL_H
#include <SFML/Graphics.hpp>
#include "Worker.h"
#include "Map.h"
#include "WeaponsUI.h"
#include "Weapontypes.h"
class Application;

class WorkerPool
{
public:
    WorkerPool();
    ~WorkerPool();
    
    void initialize(Map&, Application*);
    
    void update(float dt, Application*, Map& map);
    void draw(sf::RenderWindow&);
    
private:
    Worker m_workers[10];
    WeaponsUI m_weaponsUI;
    int m_workerCount;
    int m_selectedWorker;
    sf::Texture m_selectedTexture;
    sf::Sprite m_selectedSprite;
	bool placeWeapon = false;
};

#endif // WORKERPOOL_H
