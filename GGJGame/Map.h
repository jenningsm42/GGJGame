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
    
    int getWidth();
    int getHeight();
    
    sf::Vector2f convertToCellCoordinates(float x, float y);
    
private:
    const static int m_mapWidth = 51;
    const static int m_mapHeight = 51;
    sf::Texture m_tileTexture;
    sf::Sprite m_tileSprite;
    sf::Color m_colors[m_mapWidth * m_mapHeight];
};

#endif // MAP_H
