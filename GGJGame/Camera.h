#ifndef CAMERA_H
#define CAMERA_H
#include <SFML/Graphics.hpp>

class Camera
{
public:
    Camera();
    ~Camera();
    
    void setPosition(float x, float y);
    
    sf::Vector2f getOffset();
    
private:
    sf::Vector2f m_pos;
};

#endif // CAMERA_H
