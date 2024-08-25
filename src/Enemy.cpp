#include "headers/Enemy.h"

#include <SFML/System/Vector2.hpp>

#include "headers/ResourceManager.h"

namespace space
{
Enemy::Enemy(float positionX, float positionY)
{
    m_enemy.setTexture(ResourceManager::Instance().getTexture("resources/textures/tada.png"));
    m_enemy.setTextureRect({0, 200, 200, 200});
    m_enemy.setScale(0.3f, 0.3f);
    m_enemy.setPosition(sf::Vector2f(positionX, positionY));
}

void Enemy::update() {}

void Enemy::render(sf::RenderWindow &window) const
{
    window.draw(m_enemy);
}

} // namespace space
