#include "Worker.h"
#include <random>

Worker::Worker()
{
}

Worker::~Worker()
{
}

void Worker::initialize(Map& map)
{
    m_texture.loadFromFile("data/Stickman.png");
    m_sprite.setTexture(m_texture);
    
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> distLength(200, 300);
    std::uniform_real_distribution<float> distAngle(0, 2*3.14159f);
    
    int length = distLength(rng);
    float angle = distAngle(rng);
    m_sprite.setPosition(length * cosf(angle) + map.getWidth() / 2, length * sinf(angle) + map.getHeight() / 2);
}

void Worker::release()
{
}

void Worker::update(float dt)
{
}

void Worker::draw(sf::RenderWindow& window)
{
    window.draw(m_sprite);
}

const sf::FloatRect Worker::getBounds() const
{
    return m_sprite.getGlobalBounds();
}

const sf::Vector2f Worker::getCenter() const
{
    return m_sprite.getPosition() + 0.5f * sf::Vector2f(m_sprite.getLocalBounds().width, m_sprite.getLocalBounds().height);
}