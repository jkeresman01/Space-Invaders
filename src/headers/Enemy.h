#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>

#include "Animation.h"

namespace space
{

enum class EnemyAnimations
{
    ALIVE = 0,
    DEAD  = 1,
    COUNT = 2,
};

enum class Direction
{
    RIGHT = 0,
    LEFT  = 1,
};

class Enemy
{
  public:
    Enemy() = default;
    Enemy(float positionX, float positionY);

    void render(sf::RenderWindow &window) const;

    void update(float deltaTime);

    void changeDirection();

    sf::Vector2f getPosition() const { return m_enemy.getPosition(); }

  private:
    sf::Sprite m_enemy;
    sf::Clock m_clock;
    Direction m_direction;
    EnemyAnimations m_currentAnimation;
    Animation m_animations[int(EnemyAnimations::COUNT)];

    static constexpr float HOLD_TIME = 1.0f;

    static constexpr float SCALE_X = 0.3f;
    static constexpr float SCALE_Y = 0.3f;

    static constexpr float HORIZONTAL_MOVMENT       = 12.0f;
    static constexpr float DIRECTION_CHANGE_MOVMENT = 40.0f;
};

} // namespace space
