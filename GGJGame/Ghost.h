#ifndef Ghost_H
#define Ghost_H
#include "GameObject.h"
#include "Map.h"
#include <iostream>
#include "Command.h"
#include "Enemy.h"

class Ghost : public Enemy
{
public:
	Ghost();
	Ghost(const Ghost&);
	~Ghost();

	void initialize(Map& map, sf::Texture &m_texture) override;
	void release() override;

	void update(float dt, Map &map);
	void draw(sf::RenderWindow&) override;

	Ghost& operator=(const Ghost&);

};
#endif