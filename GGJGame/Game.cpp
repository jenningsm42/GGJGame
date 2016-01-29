#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::initialize()
{
	m_player.initialize();
}

void Game::release()
{
	m_player.release();
}

void Game::update(float dt)
{
	m_player.update(dt);
}

void Game::draw(sf::RenderWindow& window)
{
	m_player.draw(window);
}