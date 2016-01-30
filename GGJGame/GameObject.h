#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML/Graphics.hpp>
class Application;

class GameObject
{
public:
	virtual void initialize() = 0;
	virtual void release() = 0;

	virtual void update(float dt, Application*) = 0;
	virtual void draw(sf::RenderWindow&) = 0;

protected:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
};

#endif // GAMEOBJECT_H