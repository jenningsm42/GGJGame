#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <SFML/Graphics.hpp>
class Application;

class GameOver
{
public:
    GameOver();
    ~GameOver();
    
    void initialize();
    
    bool update(Application*); // true = play again
    void draw(sf::RenderWindow&);
    
private:
    sf::Font m_font;
    sf::Text m_gameOverText;
    sf::Text m_playAgainText;
    sf::RectangleShape m_background;
    sf::Clock m_timer;
};

#endif // GAMEOVER_H