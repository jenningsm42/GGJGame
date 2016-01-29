#ifndef APPLICATION_H
#define APPLICATION_H
#include <SFML/Graphics.hpp>
#include "State.h"

class Application
{
public:
	Application(State*);
	~Application();

	void setState(State*);
	bool isRunning();
	void update();

private:
	sf::RenderWindow m_window;
	State* m_curState;
	bool m_running;
};

#endif // APPLICATION_h