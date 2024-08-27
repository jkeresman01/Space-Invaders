#include "headers/Enemy.h"

#include <SFML/System/Vector2.hpp>

#include "headers/ResourceManager.h"

namespace space
{
Enemy::Enemy(float positionX, float positionY) : m_direction(Direction::RIGHT)
{
    m_enemy.setTexture(ResourceManager::Instance().getTexture("resources/textures/tada.png"));
    m_enemy.setTextureRect({0, 200, 200, 200});
    m_enemy.setScale(0.3, 0.3);
    m_enemy.setPosition(sf::Vector2f(positionX, positionY));
    m_enemy.setColor(sf::Color::White);

    m_currentAnimation = EnemyAnimations::ALIVE;
}

void Enemy::changeDirection()
{
    m_direction = m_direction == Direction::RIGHT ? Direction::LEFT : Direction::RIGHT;

    sf::Vector2f position = m_enemy.getPosition();
    position.y += 40.0f;
    position.x -= 40.0f;

    m_enemy.setPosition(position);
}

void Enemy::update()
{
    if (m_clock.getElapsedTime().asSeconds() >= HOLD_TIME)
    {
        sf::Vector2f position = m_enemy.getPosition();

        position.x += m_direction == Direction::RIGHT ? 12.0f : -12.0f;

        m_enemy.setPosition(position);
        m_clock.restart();
    }
}

void Enemy::render(sf::RenderWindow &window) const
{
    window.draw(m_enemy);
}

} // namespace space
