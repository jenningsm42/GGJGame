#include "WeaponsUI.h"
#include "Application.h"

WeaponsUI::WeaponsUI()
{
}

WeaponsUI::~WeaponsUI()
{
}

void WeaponsUI::initialize(Application* app)
{
    m_weaponTextures[0].loadFromFile("data/energy_shooter_icon.png");
    m_weaponTextures[1].loadFromFile("data/venom_blaster_icon.png");
    m_weaponTextures[2].loadFromFile("data/blowdart_icon.png");
    
    for(int i = 0; i < 3; i++)
    {
        m_weaponSprites[i].setTexture(m_weaponTextures[i]);
        m_weaponSprites[i].setColor(sf::Color(220, 220, 220, 255));
    }
}

void WeaponsUI::update(Application* app, WeaponUIStatus &retval)
{
    for(int i = 0; i < 3; i++)
        m_weaponSprites[i].setPosition(app->getWidth() / 2 - m_weaponTextures[i].getSize().x - 50 + app->getView()->getCenter().x, 50 + (m_weaponTextures[i].getSize().y + 50) * i + app->getView()->getCenter().y - app->getHeight() / 2);
    
    sf::Vector2i mpos = sf::Mouse::getPosition() + (sf::Vector2i)app->getView()->getCenter();
    mpos.x -= app->getWidth() / 2;
    mpos.y -= app->getHeight() / 2;
    
    for(int i = 0; i < 3; i++)
    {
        sf::Vector2i pos = (sf::Vector2i)m_weaponSprites[i].getPosition();
        pos.x += m_weaponTextures[i].getSize().x / 2;
        pos.y += m_weaponTextures[i].getSize().y / 2;
        
        int dx = mpos.x - pos.x;
        int dy = mpos.y - pos.y;
        int len = dx*dx + dy*dy;
        int radius = (m_weaponTextures[i].getSize().x / 2) * (m_weaponTextures[i].getSize().x / 2);
        
		if (len < radius)
		{
			m_weaponSprites[i].setColor(sf::Color::White);
			retval.isHover = true;
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				switch (i) {
                    case 0: retval.weaponType = WeaponType::Shooter; break;
                    case 1: retval.weaponType = WeaponType::Trap; break;
                    case 2: retval.weaponType = WeaponType::Acid; break;
                    case 3: retval.weaponType = WeaponType::Wall; break;
                    default: retval.weaponType = WeaponType::None; break;
				}
				 
			}
		}
        else m_weaponSprites[i].setColor(sf::Color(220, 220, 220, 255));
    }
}

void WeaponsUI::draw(sf::RenderWindow& window)
{
    for(int i = 0; i < 3; i++)
        window.draw(m_weaponSprites[i]);
}