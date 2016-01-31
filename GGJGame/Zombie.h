#ifndef Zombie_H
#define Zombie_H
#include "GameObject.h"
#include "Map.h"
#include <iostream>
#include "Command.h"
#include "Enemy.h"

class Zombie : public Enemy
{
public:
	Zombie();
    Zombie(const Zombie&);
	~Zombie();

	void initialize(Map& map, sf::Texture &m_texture) override;
	void release() override;

	void update(float dt, Map &map);
	void draw(sf::RenderWindow&) override;

	const sf::FloatRect getBounds() const;
	const sf::Vector2f getCenter() const;
    
    Zombie& operator=(const Zombie&);

};

#endif // Zombie_H