#include "Announcements.h"
#include "Application.h"

Announcements::Announcements() : m_color(sf::Color(255, 255, 0)), m_delay(10.f)
{
    m_font.loadFromFile("data/amatic.ttf");
    m_text.setFont(m_font);
    m_text.setCharacterSize(80);
    m_text.setColor(sf::Color(255, 255, 0));
    m_text.setStyle(sf::Text::Bold);
    m_text.setString("Hello, world!");
}

Announcements::~Announcements()
{
}

void Announcements::setAnnouncement(std::string announcement, sf::Color color, float delay)
{
    m_text.setString(announcement);
    m_color = color;
    m_delay = delay;
    m_text.setColor(color);
    m_timer.restart();
}

void Announcements::update(Application* app)
{
    float time = m_timer.getElapsedTime().asSeconds();
    if(time > m_delay + 1.f) return;
    
    if(time >= m_delay)
    {
        float alpha = 1.f - (time - m_delay);
        m_color.a = 255.f * alpha;
        m_text.setColor(m_color);
    }
    
    m_text.setPosition(app->getView()->getCenter().x - m_text.getLocalBounds().width / 2,
                       app->getView()->getCenter().y - app->getHeight() / 2 + 100);
}

void Announcements::draw(sf::RenderWindow& window)
{
    window.draw(m_text);
}