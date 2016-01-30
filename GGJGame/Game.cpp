#include "Game.h"
#include "Application.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::initialize()
{
}

void Game::release()
{
}

void Game::update(float dt, Application* app)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        app->getView()->move(300 * dt, 0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        app->getView()->move(-300 * dt, 0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        app->getView()->move(0, -300 * dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        app->getView()->move(0, 300 * dt);
}

void Game::draw(sf::RenderWindow& window)
{
	m_map.draw(window);
}