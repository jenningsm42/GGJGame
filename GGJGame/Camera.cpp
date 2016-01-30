#include "Camera.h"

Camera::Camera()
{
}

Camera::~Camera()
{
}

void Camera::setPosition(float x, float y)
{
    m_pos = sf::Vector2f(x, y);
}

sf::Vector2f Camera::getOffset()
{
    return m_pos;
}