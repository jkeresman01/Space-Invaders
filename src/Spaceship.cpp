#include "headers/Spaceship.h"

#include "headers/ResourceManager.h"

#include <SFML/Graphics.hpp>

namespace space
{

Spaceship::Spaceship() : m_position(1280 / 2.0f, 620)
{
    m_spaceship.setTexture(ResourceManager::Instance().getTexture("resources/textures/tada.png"));
    m_spaceship.setTextureRect({0, 0, 200, 200});
    m_spaceship.setScale(0.5f, 0.5f);
    m_spaceship.setPosition(m_position);
}

void Spaceship::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_position.x -= 1.0f;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_position.x += 1.0f;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        sf::Vector2f positon = m_spaceship.getPosition();
        positon.x += 40.0f;

        m_bullets.emplace_back(positon);
    }

    std::vector<Bullet>::iterator it = m_bullets.begin();

    while (it != m_bullets.end())
    {
        it->update();

        if (it->getPositon().y <= 0)
        {
            it = m_bullets.erase(it);
        }
        else
        {
            ++it;
        }
    }

    m_spaceship.setPosition(m_position);
}

void Spaceship::render(sf::RenderWindow &window) const
{
    window.draw(m_spaceship);

    for (const Bullet &bullet : m_bullets)
    {
        bullet.render(window);
    }
}

} // namespace space
