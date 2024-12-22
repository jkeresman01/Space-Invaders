#pragma once

#include "Enemy.h"
#include "Spaceship.h"

#include <SFML/Graphics/RenderWindow.hpp>

namespace space
{
class SpaceInvaders
{
  public:
    SpaceInvaders()                      = default;
    SpaceInvaders(const SpaceInvaders &) = delete;
    SpaceInvaders(SpaceInvaders &&)      = delete;
    SpaceInvaders &operator=(const SpaceInvaders &) = delete;
    SpaceInvaders &operator=(SpaceInvaders &&) = delete;

    void init();
    void shutdown();

    void run();

  private:
    void initWindow();
    void initEnemies();

    void processEvents();
    void checkForDirectionChange();

    void update();
    void updateEnemies();

    void render();
    void renderEnemies();

  private:
    sf::RenderWindow m_window;
    std::vector<Enemy> m_enemies;
    Spaceship m_spaceship;
    bool m_changeDirection;

    static constexpr uint32_t INIT_WINDOW_WITH   = 1280;
    static constexpr uint32_t INIT_WINDOW_HEIGHT = 720;
};
} // namespace space
