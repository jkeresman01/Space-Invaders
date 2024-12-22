#include "headers/Spaceship.h"

#include <SFML/Graphics.hpp>

#include "headers/ResourceManager.h"
#include "headers/Sound.h"
#include "headers/Textures.h"

namespace space
{

Spaceship::Spaceship() : m_position(1280 / 2.0f, 620)
{
    m_spaceship.setTexture(ResourceManager::Instance().getTexture(textures::Spaceship));
    m_spaceship.setPosition(m_position);
    m_spaceship.setScale(SCALE_X, SCALE_Y);

    m_shootingSoundEffect.setBuffer(ResourceManager::Instance().getSoundBuffer(sound::Shooting));
}

void Spaceship::processEvents()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_position.x -= 1.0f;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_position.x += 1.0f;
    }
}

void Spaceship::update()
{
    bool isReloadTimerExpired = m_clock.getElapsedTime().asSeconds() >= RELOAD_TIME;
    bool isSpacePressed       = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

    if (isSpacePressed and isReloadTimerExpired)
    {
        sf::Vector2f bulletPosition = m_spaceship.getPosition();
        bulletPosition.x += 45.0f;

        m_bullets.emplace_back(bulletPosition);

        m_shootingSoundEffect.play();
        m_clock.restart();
    }

    updateBullets();

    m_spaceship.setPosition(m_position);
}

void Spaceship::updateBullets()
{
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
}

void Spaceship::render(sf::RenderWindow &window) const
{
    window.draw(m_spaceship);
    renderBullets(window);
}

void Spaceship::renderBullets(sf::RenderWindow &window) const
{
    for (const Bullet &bullet : m_bullets)
    {
        bullet.render(window);
    }
}

} // namespace space
