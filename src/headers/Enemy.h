#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

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
};

} // namespace space
