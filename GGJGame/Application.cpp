#include "Application.h"

Application::Application(State* state) : m_running(true)
{
	setState(state);
	m_window.create(sf::VideoMode(800, 600), "GGJGame");
}

Application::~Application()
{
	m_window.close();
}

void Application::setState(State* state)
{
	if (m_curState != nullptr)
	{
		m_curState->release();
		delete m_curState;
	}

	m_curState = state;
	if(m_curState != nullptr)
		m_curState->initialize();
}

bool Application::isRunning()
{
	return m_running;
}

void Application::update()
{
	static sf::Clock clock;
	static sf::Time elapsedTime = sf::milliseconds(16.67f);

	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_running = false;
	}

	m_window.clear(sf::Color::Black);

	if (m_curState != nullptr)
	{
		m_curState->update(elapsedTime.asSeconds());
		m_curState->draw(m_window);
	}

	m_window.display();

	elapsedTime = clock.restart();
}