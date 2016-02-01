#include "Bar.h"
#include "Application.h"

Bar::Bar(int max) : m_maximum(max)
{
    m_barBackground = new sf::RectangleShape();
    m_barFill = new sf::RectangleShape();
    m_barBackground->setSize(sf::Vector2f(70, 10));
    m_barBackground->setFillColor(sf::Color::Black);
    m_barFill->setSize(sf::Vector2f(0, 8));
    m_barFill->setFillColor(sf::Color::Red);
}

Bar::~Bar()
{
    delete m_barBackground;
    delete m_barFill;
}

void Bar::setCurrentValue(int val)
{
    m_current = val;
    
    m_barFill->setSize(sf::Vector2f(68 * (float)val / (float)m_maximum, 8));
}

void Bar::setFillColor(sf::Color color)
{
    m_barFill->setFillColor(color);
}

void Bar::update(sf::Vector2f target)
{
    m_barBackground->setPosition(target.x - m_barBackground->getSize().x / 2, target.y + 50);
    m_barFill->setPosition(m_barBackground->getPosition() + sf::Vector2f(1.f, 1.f));
}

void Bar::draw(sf::RenderWindow& window)
{
    window.draw(*m_barBackground);
    window.draw(*m_barFill);
}

Bar& Bar::operator=(const Bar& other)
{
    m_barBackground = other.m_barBackground;
    m_barFill = other.m_barFill;
    m_maximum = other.m_maximum;
    m_current = other.m_current;
}