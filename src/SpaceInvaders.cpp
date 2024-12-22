#include "headers/SpaceInvaders.h"
#include <SFML/Window/Event.hpp>

namespace space
{
void SpaceInvaders::init()
{
    initWindow();
    initEnemies();
}

void SpaceInvaders::initWindow()
{
    m_window.create(sf::VideoMode(INIT_WINDOW_WITH, INIT_WINDOW_HEIGHT), "Space Invaders");
}

void SpaceInvaders::initEnemies()
{
    for (size_t i = 0; i < 5; ++i)
    {
        for (size_t j = 0; j < 11; ++j)
        {
            float positionX = 200 + j * (40 + 30);
            float positionY = 50 + i * (40 + 20);

            m_enemies.emplace_back(positionX, positionY);
        }
    }
}

void SpaceInvaders::shutdown() {}

void SpaceInvaders::run()
{
    while (m_window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void SpaceInvaders::processEvents()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_window.close();
        }

        checkForDirectionChange();
    }
}

void SpaceInvaders::checkForDirectionChange()
{
    for (const Enemy &enemy : m_enemies)
    {
        if (enemy.getPosition().x >= INIT_WINDOW_HEIGHT - 40 or enemy.getPosition().x <= 0)
        {
            m_changeDirection = true;
            break;
        }
    }
}

void SpaceInvaders::update()
{
    m_spaceship.update();
    updateEnemies();
}

void SpaceInvaders::updateEnemies()
{
    for (Enemy &enemy : m_enemies)
    {
        enemy.update();
    }
}

void SpaceInvaders::render()
{
    m_window.clear();
    m_spaceship.render(m_window);
    renderEnemies();
    m_window.display();
}

void SpaceInvaders::renderEnemies()
{
    for (const Enemy &enemy : m_enemies)
    {
        enemy.render(m_window);
    }
}
} // namespace space
