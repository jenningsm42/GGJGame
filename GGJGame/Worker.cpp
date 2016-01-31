#include "Worker.h"
#include <random>

Worker::Worker() : m_speed(200.f)
{
    m_curCommand.commandType = CommandType::None;
}

Worker::~Worker()
{
}

void Worker::initialize(Map& map)
{
    m_texture.loadFromFile("data/worker_front.png");
    m_sprite.setTexture(m_texture);
    
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> distLength(200, 300);
    std::uniform_real_distribution<float> distAngle(0, 2*3.14159f);
    
    int length = distLength(rng);
    float angle = distAngle(rng);
    sf::Vector2f pos = sf::Vector2f(length * cosf(angle) + map.getWidth() / 2, length * sinf(angle) + map.getHeight() / 2);
    pos = map.convertToCellCoordinates(pos.x, pos.y);
    m_sprite.setPosition(pos.x - m_sprite.getLocalBounds().width / 2, pos.y - m_sprite.getLocalBounds().height + 20);
}

void Worker::release()
{
}

void Worker::update(float dt, Map &map, WeaponPool &weaponPool)
{
    switch(m_curCommand.commandType)
    {
        case CommandType::Move:
        {
            float dx = m_curCommand.x - getCenter().x;
            float dy = m_curCommand.y - getCenter().y - m_sprite.getLocalBounds().height / 2 + 20;
            
            if(fabsf(dx) < 5.f && fabsf(dy) < 5.f)
            {
                m_sprite.setPosition(m_curCommand.x - m_sprite.getLocalBounds().width / 2,
                                     m_curCommand.y - m_sprite.getLocalBounds().height + 20);
                
                m_curCommand.commandType = CommandType::None;
                break;
            }
            
            float angle = atan2f(dy, dx);
            m_sprite.move(m_speed * cosf(angle) * dt, m_speed * sinf(angle) * dt);
        } break;
        case CommandType::Place:
        {
			float dx = m_curCommand.x - getCenter().x;
			float dy = m_curCommand.y - getCenter().y - m_sprite.getLocalBounds().height / 2 + 20;

			if (fabsf(dx) < 5.f && fabsf(dy) < 5.f)
            {
                m_sprite.setPosition(m_curCommand.x - m_sprite.getLocalBounds().width / 2,
                                     m_curCommand.y - m_sprite.getLocalBounds().height + 20);
                
				weaponPool.placeWeapon(m_curCommand.weaponType, m_curCommand.x, m_curCommand.y, map);
				m_curCommand.commandType = CommandType::None;
				break;
			}

			float angle = atan2f(dy, dx);
			m_sprite.move(m_speed * cosf(angle) * dt, m_speed * sinf(angle) * dt);


        } break;
        default: break;
    }
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

void Worker::setCommand(Command& command)
{
    m_curCommand = command;
}