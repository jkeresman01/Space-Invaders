#pragma once

#include <SFML/Audio/Sound.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>

#include "Bullet.h"

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
    void renderBullets(sf::RenderWindow &window) const;

  private:
    sf::Sprite m_spaceship;
    sf::Clock m_clock;
    sf::Vector2f m_position;
    sf::Sound m_shootingSoundEffect;
    std::vector<Bullet> m_bullets;

    static constexpr float RELOAD_TIME = 0.8f;

    static constexpr float SCALE_X = 2.0f;
    static constexpr float SCALE_Y = 2.0f;
};

} // namespace space
