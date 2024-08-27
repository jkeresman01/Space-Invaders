#include "headers/Bullet.h"

namespace space
{
Bullet::Bullet(const sf::Vector2f &position)
{
    m_bullet.setSize(sf::Vector2f(6.0f, 12.0f));
    m_bullet.setFillColor(sf::Color::Green);
    m_bullet.setPosition(position);
}

void Bullet::update()
{
    sf::Vector2f postion = m_bullet.getPosition();
    postion.y -= 2.0f;

    m_bullet.setPosition(postion);
}

void Bullet::render(sf::RenderWindow &window) const
{
    window.draw(m_bullet);
}

} // namespace space
