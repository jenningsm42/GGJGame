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

void Worker::update(float dt, Application* app)
{
}

void Worker::draw(sf::RenderWindow& window)
{
    window.draw(m_sprite);
}