#pragma once

#include "Bullet.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

#include <cstdint>
#include <vector>

namespace space
{
class Spaceship
{
  public:
    Spaceship();

    void update();

    void render(sf::RenderWindow &window) const;

  private:
    sf::Sprite m_spaceship;
    sf::Vector2f m_position;
    std::vector<Bullet> m_bullets;
};

} // namespace space
