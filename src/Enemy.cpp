#include "headers/Enemy.h"

#include <SFML/System/Vector2.hpp>

namespace space
{
Enemy::Enemy(float positionX, float positionY)
    : m_direction(Direction::RIGHT), m_currentAnimation(EnemyAnimations::ALIVE)
{
    m_animations[int(EnemyAnimations::ALIVE)] =
        Animation(0, 200, 500, 200, 2, "resources/textures/tada.png");

    m_enemy.setScale(SCALE_X, SCALE_Y);
    m_enemy.setPosition(sf::Vector2f(positionX, positionY));
}

void Enemy::changeDirection()
{
    m_direction = (m_direction == Direction::RIGHT) ? Direction::LEFT : Direction::RIGHT;

    sf::Vector2f position = m_enemy.getPosition();
    position.y += 40.0f;
    position.x -= 40.0f;

    m_enemy.setPosition(position);
}

void Enemy::update(float deltaTime)
{
    if (m_clock.getElapsedTime().asSeconds() >= HOLD_TIME)
    {
        sf::Vector2f position = m_enemy.getPosition();

        position.x += (m_direction == Direction::RIGHT) ? HORIZONTAL_MOVMENT : -HORIZONTAL_MOVMENT;

        m_animations[int(m_currentAnimation)].update(deltaTime);
        m_animations[int(m_currentAnimation)].applyToSprite(m_enemy);

        m_enemy.setPosition(position);
        m_clock.restart();
    }
}

void Enemy::render(sf::RenderWindow &window) const
{
    window.draw(m_enemy);
}

} // namespace space
