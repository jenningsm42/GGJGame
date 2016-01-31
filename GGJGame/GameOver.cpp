#include "GameOver.h"
#include "Application.h"

GameOver::GameOver()
{
}

GameOver::~GameOver()
{
}

void GameOver::initialize()
{
    m_font.loadFromFile("data/amatic.ttf");
    m_gameOverText.setFont(m_font);
    m_gameOverText.setString("GAME OVER");
    m_gameOverText.setCharacterSize(120);
    m_gameOverText.setColor(sf::Color::Red);
    m_playAgainText.setFont(m_font);
    m_playAgainText.setString("Play again?");
    m_playAgainText.setCharacterSize(68);
    m_playAgainText.setColor(sf::Color(150, 150, 150));
}

bool GameOver::update(Application* app)
{
    sf::Vector2f vpos = app->getView()->getCenter();
    m_background.setPosition(vpos.x - app->getWidth() / 2, vpos.y - app->getHeight() / 2);
    m_gameOverText.setPosition(vpos.x - m_gameOverText.getLocalBounds().width / 2,
                               vpos.y - app->getHeight() / 2 + 200);
    m_playAgainText.setPosition(vpos.x - m_playAgainText.getLocalBounds().width / 2, vpos.y + 100);
    
    sf::Vector2f mpos = (sf::Vector2f)sf::Mouse::getPosition() + app->getView()->getCenter();
    mpos.x -= app->getWidth() / 2;
    mpos.y -= app->getHeight() / 2;
    
    if(m_playAgainText.getGlobalBounds().contains(mpos))
    {
        m_playAgainText.setColor(sf::Color::White);
        
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            return true;
    }
    else m_playAgainText.setColor(sf::Color(220, 220, 220));
    
    return false;
}

void GameOver::draw(sf::RenderWindow& window)
{
    window.draw(m_gameOverText);
    window.draw(m_playAgainText);
}