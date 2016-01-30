#ifndef STATE_H
#define STATE_H
#include <SFML/Graphics.hpp>
class Application;

class State
{
public:
	virtual void initialize() = 0;
	virtual void release() = 0;

	virtual void update(float dt, Application*) = 0;
	virtual void draw(sf::RenderWindow&) = 0;
};

#endif // STATE_H