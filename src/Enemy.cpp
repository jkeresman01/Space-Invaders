#include "headers/Enemy.h"

#include <SFML/System/Vector2.hpp>

#include "headers/ResourceManager.h"

namespace space
{
Enemy::Enemy(float positionX, float positionY)
    : m_direction(Direction::RIGHT), m_currentAnimation(EnemyAnimations::ALIVE)
{
    m_enemy.setTexture(ResourceManager::Instance().getTexture("resources/textures/tada.png"));
    m_enemy.setTextureRect({0, 200, 200, 200});

    m_enemy.setScale(SCALE_X, SCALE_Y);
    m_enemy.setPosition(sf::Vector2f(positionX, positionY));
}

void Enemy::changeDirection()
{
    m_direction = (m_direction == Direction::RIGHT) ? Direction::LEFT : Direction::RIGHT;
    m_enemy.move(-DIRECTION_CHANGE_MOVMENT, DIRECTION_CHANGE_MOVMENT);
}

void Enemy::update()
{
    if (m_clock.getElapsedTime().asSeconds() >= HOLD_TIME)
    {
        float movement =
            (m_direction == Direction::RIGHT) ? HORIZONTAL_MOVMENT : -HORIZONTAL_MOVMENT;
        m_enemy.move(movement, 0);

        m_clock.restart();
    }
}

void Enemy::render(sf::RenderWindow &window) const
{
    window.draw(m_enemy);
}

} // namespace space
