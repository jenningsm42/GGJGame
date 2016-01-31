#ifndef CURRENCY_H
#define CURRENCY_H
#include <SFML/Graphics.hpp>
#include "WeaponTypes.h"
class Application;

class Currency
{
public:
    Currency();
    ~Currency();
    
    void addCurrency(int amount);
    void deductCurrency(int amount);
    
    int getCurrency();
    
    int getPrice(WeaponType);
    
    void update(Application*);
    void draw(sf::RenderWindow&);
    
private:
    int m_currency;
    sf::Texture m_iconTexture;
    sf::Sprite m_iconSprite;
    sf::Font m_font;
    sf::Text m_text;
};

#endif // CURRENCY_H