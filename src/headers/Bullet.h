#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

namespace space
{

class Bullet
{
  public:
    Bullet() = default;
    explicit Bullet(const sf::Vector2f &positon);

    void update();

    void render(sf::RenderWindow &window) const;

    sf::Vector2f getPositon() const { return m_bullet.getPosition(); }

  private:
    sf::RectangleShape m_bullet;

    static constexpr float WIDTH  = 6.0f;
    static constexpr float HEIGHT = 12.0f;
};

} // namespace space
