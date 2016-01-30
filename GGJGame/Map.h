#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp>
class Camera;

class Map
{
public:
    Map();
    ~Map();
    
    void update(Camera* camera);
    void draw(sf::RenderWindow&);
    
private:
    const static int m_mapWidth = 100;
    const static int m_mapHeight = 100;
    sf::Texture m_tileTexture;
    sf::Sprite m_tileSprite;
    sf::Color m_colors[m_mapWidth * m_mapHeight];
};

#endif // MAP_H
