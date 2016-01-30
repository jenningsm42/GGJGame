#include "Map.h"
#include <random>

Map::Map()
{
    m_tileTexture.loadFromFile("data/64x72.png");
    m_tileSprite.setTexture(m_tileTexture);
    
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_real_distribution<double> dist(0.0,1.0);
    
    for(int i = 0; i < m_mapWidth * m_mapHeight; i++)
    {
        double rand = dist(rng);
        m_colors[i] = sf::Color(rand * 40 + 25, rand * 40 + 60, rand * 20 + 50);
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
            m_tileSprite.setPosition(y%2==0? x*64 : x*64 + 32, y*54);
            window.draw(m_tileSprite);
        }
    }
}