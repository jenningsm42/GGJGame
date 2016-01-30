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
    
    sf::View* getView();

private:
	sf::RenderWindow m_window;
    sf::View m_view;
	State* m_curState;
    int m_width;
    int m_height;
	bool m_running;
    bool m_focused;
};

#endif // APPLICATION_h