#include "Currency.h"
#include "Application.h"
#include <string>

Currency::Currency() : m_currency(225)
{
    m_font.loadFromFile("data/amatic.ttf");
    m_text.setFont(m_font);
    m_text.setColor(sf::Color::Yellow);
    m_text.setString(std::to_string(m_currency));
    m_text.setCharacterSize(48);
    
    m_iconTexture.loadFromFile("data/bacteria.png");
    m_iconSprite.setTexture(m_iconTexture);
}

Currency::~Currency()
{
}

void Currency::addCurrency(int amount)
{
    m_currency += amount;
    m_text.setString(std::to_string(m_currency));
}

void Currency::deductCurrency(int amount)
{
    m_currency -= amount;
    m_text.setString(std::to_string(m_currency));
}

int Currency::getCurrency()
{
    return m_currency;
}

int Currency::getPrice(WeaponType type)
{
    switch(type)
    {
        case WeaponType::Shooter: return 75;
        case WeaponType::Acid: return 200;
        case WeaponType::Blowdart: return 500;
        default: return 0;
    }
}

void Currency::update(Application* app)
{
    float x = app->getView()->getCenter().x - app->getWidth() / 2 + 20;
    float y = app->getView()->getCenter().y - app->getHeight() / 2 + 20;
    m_text.setPosition(x + m_iconTexture.getSize().x + 10, y);
    m_iconSprite.setPosition(x, y + 5);
}

void Currency::draw(sf::RenderWindow& window)
{
    window.draw(m_text);
    window.draw(m_iconSprite);
}