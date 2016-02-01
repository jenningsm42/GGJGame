#include "BossGhost.h"
#include <random>

BossGhost::BossGhost()
{
	m_speed = 65;
	m_health = 400;
    m_type = 1;
}

BossGhost::BossGhost(const BossGhost& other)
{
	m_sprite = other.m_sprite;
	m_speed = other.m_speed;
	m_health = other.m_health;
    m_type = 1;
}

BossGhost::~BossGhost()
{
}

void BossGhost::initialize(Map &map, sf::Texture &m_texture)
{
	m_sprite.setTexture(m_texture);
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_real_distribution<float> distLength(1550.f, 1600.f);
	std::uniform_real_distribution<float> distAngle(0, 2 * 3.14159f);

	float length = distLength(rng);
	float angle = distAngle(rng);
	m_sprite.setPosition(length * cosf(angle) + map.getWidth() / 2, length * sinf(angle) + map.getHeight() / 2);
}

void BossGhost::release()
{
}

void BossGhost::update(float dt, Map &map)
{
	float my_x = m_sprite.getPosition().x;
	float my_y = m_sprite.getPosition().y;

	float dx = map.getWidth() / 2 - getCenter().x;
	float dy = map.getHeight() / 2 - getCenter().y - m_sprite.getLocalBounds().height / 2 + 20;
	float angle = atan2f(dy, dx);
	m_sprite.move(cosf(angle)*dt*m_speed, sinf(angle)*dt*m_speed);
}

void BossGhost::draw(sf::RenderWindow &window)
{
	window.draw(m_sprite);
}


BossGhost& BossGhost::operator=(const BossGhost& other)
{
	m_sprite = other.m_sprite;
	m_speed = other.m_speed;
	m_health = other.m_health;
	return *this;
}