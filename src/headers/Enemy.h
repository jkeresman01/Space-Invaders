#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>

namespace space
{

class Enemy
{
  public:
    Enemy() = default;
    Enemy(float positionX, float positionY);

    void update();

    void render(sf::RenderWindow &window) const;

  private:
    sf::Sprite m_enemy;
    sf::Clock m_clock;

    static constexpr float HOLD_TIME = 1.0f;
};

} // namespace space
