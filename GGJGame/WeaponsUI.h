#ifndef WEAPONSUI_H
#define WEAPONSUI_H
#include <SFML/Graphics.hpp>
#include "WeaponTypes.h"
class Application;

class WeaponsUI
{
public:
    WeaponsUI();
    ~WeaponsUI();
    
    void initialize(Application*);
    
    void update(Application*, WeaponUIStatus &weapon);
    void draw(sf::RenderWindow&);
    
private:
    sf::Texture m_weaponTextures[3];
    sf::Sprite m_weaponSprites[3];
};

#endif // WEAPONSUI_H
