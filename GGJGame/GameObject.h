#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML/Graphics.hpp>
class Application;

class GameObject
{
public:
    virtual void initialize() {}
    virtual void release() {}

    virtual void update(float dt, Application*) {}
    virtual void draw(sf::RenderWindow&) {}

protected:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
};

#endif // GAMEOBJECT_H