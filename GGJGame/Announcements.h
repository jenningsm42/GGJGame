#ifndef ANNOUNCEMENTS_H
#define ANNOUNCEMENTS_H
#include <SFML/Graphics.hpp>
#include "Map.h"
class Application;

class Announcements
{
public:
    Announcements();
    ~Announcements();
    
    void setAnnouncement(std::string, sf::Color = sf::Color(255, 255, 0), float delay = 10.f);
    
    void update(Application*);
    void draw(sf::RenderWindow&);
    
private:
    sf::Font m_font;
    sf::Text m_text;
    sf::Color m_color;
    sf::Clock m_timer;
    float m_delay;
};

#endif // ANNOUNCEMENTS_H