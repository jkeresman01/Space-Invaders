#include "headers/Spaceship.h"

#include "headers/ResourceManager.h"

#include <SFML/Graphics.hpp>
#include <algorithm>

namespace space
{

Spaceship::Spaceship() : m_position(1280 / 2.0f, 620)
{
    m_spaceship.setTexture(ResourceManager::Instance().getTexture("resources/textures/ship.png"));
    m_spaceship.setPosition(m_position);
    m_spaceship.setScale(SCALE_X, SCALE_Y);

    m_shootingSoundEffect.setBuffer(
        ResourceManager::Instance().getSoundBuffer("resources/sound/shooting.wav"));
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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and
        m_clock.getElapsedTime().asSeconds() >= RELOAD_TIME)
    {
        sf::Vector2f positon = m_spaceship.getPosition();
        positon.x += 40.0f;

        m_bullets.emplace_back(positon);

        m_shootingSoundEffect.play();
        m_clock.restart();
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
    renderBullets(window);
}

void Spaceship::renderBullets(sf::RenderWindow &window) const
{
    std::for_each(m_bullets.begin(), m_bullets.end(), [&window](const Bullet &bullet) { bullet.render(window); } );
}

} // namespace space
