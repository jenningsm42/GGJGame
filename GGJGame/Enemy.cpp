#include "Enemy.h"
#include <random>


Enemy::Enemy()
{

}

Enemy::~Enemy()
{
}

void Enemy::initialize(Map & map, sf::Texture &m_texture)
{
	m_sprite.setTexture(m_texture);
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_real_distribution<float> distLength(1550.f,1600.f);
	std::uniform_real_distribution<float> distAngle(0, 2 * 3.14159f);

	float length = distLength(rng);
	float angle = distAngle(rng);
	m_sprite.setPosition(length * cosf(angle) + map.getWidth() / 2, length * sinf(angle) + map.getHeight() / 2);
	std::cout << m_sprite.getPosition().x;
	std::cout << "\n";
	std::cout << m_sprite.getPosition().y;
	std::cout << "\n";
}

void Enemy::release()
{
}

void Enemy::update(float dt, Map &map)
{
	float my_x = m_sprite.getPosition().x;
	float my_y = m_sprite.getPosition().y;

	
}

void Enemy::draw(sf::RenderWindow &window)
{
	window.draw(m_sprite);
}

const sf::FloatRect Enemy::getBounds() const
{
	return m_sprite.getGlobalBounds();
}

const sf::Vector2f Enemy::getCenter() const
{
	return m_sprite.getPosition() + 0.5f * sf::Vector2f(m_sprite.getLocalBounds().width, m_sprite.getLocalBounds().height);
}
