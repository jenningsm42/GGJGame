#include "Map.h"
#include <random>

Map::Map()
{
    m_tileTexture.loadFromFile("data/cell.png");
    m_tileSprite.setTexture(m_tileTexture);
    
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_real_distribution<double> dist(0.0,1.0);
    
    for(int i = 0; i < m_mapWidth * m_mapHeight; i++)
    {
        double rand = dist(rng);
        m_colors[i] = sf::Color(rand * 20 + 25, rand * 20 + 70, rand * 10 + 50);
    }
}

Map::~Map()
{
}

void Map::draw(sf::RenderWindow& window)
{
    for(int y = 0; y < m_mapHeight; y++)
    {
        for(int x = 0; x < m_mapWidth; x++)
        {
            m_tileSprite.setColor(m_colors[y * m_mapWidth + x]);
            m_tileSprite.setPosition(x*64, y*64);
            window.draw(m_tileSprite);
        }
    }
}

int Map::getWidth()
{
    return m_mapWidth * m_tileTexture.getSize().x;
}

int Map::getHeight()
{
    return m_mapHeight * 54 + 18;
}

sf::Vector2f Map::convertToCellCoordinates(float x, float y)
{
    return sf::Vector2f();
}