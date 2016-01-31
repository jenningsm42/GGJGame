#ifndef ANNOUNCEMENTS_H
#define ANNOUNCEMENTS_H
#include <SFML/Graphics.hpp>
#include "Map.h"

class Announcements
{
public:
    Announcements();
    ~Announcements();
    
    void setAnnouncement(std::string);
    
    void update(float dt, Map& map);
    void draw(sf::RenderWindow&);
    
private:
    sf::Font m_font;
    sf::Text m_text;
};

#endif // ANNOUNCEMENTS_H