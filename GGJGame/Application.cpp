#include "Application.h"

Application::Application(State* state) : m_running(true), m_focused(true)
{
    m_width = sf::VideoMode::getDesktopMode().width;
    m_height = sf::VideoMode::getDesktopMode().height;
    
    m_window.create(sf::VideoMode::getDesktopMode(), "Ritual Defence", sf::Style::Fullscreen);
    //m_window.setVerticalSyncEnabled(true);
    m_view.reset(sf::FloatRect(0, 0, m_width, m_height));
    
    setState(state);
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
    {
		m_curState->initialize(this);
        m_window.setView(m_view);
    }
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
        if (event.type == sf::Event::LostFocus)
            m_focused = false;
        if (event.type == sf::Event::GainedFocus)
            m_focused = true;
	}

    if(m_focused)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            m_running = false;
        
        m_window.clear(sf::Color::Black);

        if (m_curState != nullptr)
        {
            m_curState->update(elapsedTime.asSeconds(), this);
            m_window.setView(m_view);
            
            m_curState->draw(m_window);
        }

        m_window.display();
    }

	elapsedTime = clock.restart();
}

int Application::getWidth()
{
    return m_width;
}

int Application::getHeight()
{
    return m_height;
}

sf::View* Application::getView()
{
    return &m_view;
}