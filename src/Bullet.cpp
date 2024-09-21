#include "headers/Bullet.h"

#include "headers/Colors.h"

namespace space
{

Bullet::Bullet(const sf::Vector2f &position)
{
    m_bullet.setSize(sf::Vector2f(WIDTH, HEIGHT));
    m_bullet.setFillColor(colors::Green);
    m_bullet.setPosition(position);
}

void Bullet::update()
{
    m_bullet.move(MOVEMENT_X, -MOVEMENT_Y);
}

void Bullet::render(sf::RenderWindow &window) const
{
    window.draw(m_bullet);
}

} // namespace space
