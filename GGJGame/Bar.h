#ifndef BAR_H
#define BAR_H
#include <SFML/Graphics.hpp>
class Application;

class Bar
{
public:
    Bar(int maximum);
    ~Bar();
    
    void setCurrentValue(int);
    void setFillColor(sf::Color);
    
    void update(sf::Vector2f target);
    void draw(sf::RenderWindow&);
    
    Bar& operator=(const Bar&);
    
private:
    sf::RectangleShape* m_barBackground;
    sf::RectangleShape* m_barFill;
    int m_maximum;
    int m_current;
};

#endif // BAR_H