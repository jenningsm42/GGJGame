#include "Player.h"
#include "Application.h"

void Player::initialize()
{
	m_texture.loadFromFile("data/test.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(sf::Vector2f(400 - m_texture.getSize().x / 2, 300 - m_texture.getSize().y / 2));
    m_sprite.setColor(sf::Color(255, 0, 0, 128));
}

void Player::release()
{
}

void Player::update(float dt, Application* app)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		m_sprite.move(sf::Vector2f(m_speed * dt, 0));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		m_sprite.move(sf::Vector2f(-m_speed * dt, 0));
	if (m_sprite.getPosition().x < 0)
		m_sprite.setPosition(0, m_sprite.getPosition().y);
	if (m_sprite.getPosition().x + m_sprite.getLocalBounds().width > 800)
        m_sprite.setPosition(800 - m_sprite.getLocalBounds().width, m_sprite.getPosition().y);
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}