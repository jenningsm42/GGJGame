#ifndef WEAPONSUI_H
#define WEAPONSUI_H
#include <SFML/Graphics.hpp>
class Application;

class WeaponsUI
{
public:
    WeaponsUI();
    ~WeaponsUI();
    
    void initialize(Application*);
    
    bool update(Application*);
    void draw(sf::RenderWindow&);
    
private:
    sf::Texture m_weaponTextures[3];
    sf::Sprite m_weaponSprites[3];
};

#endif // WEAPONSUI_H
