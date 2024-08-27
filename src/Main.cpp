#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <chrono>

#include "headers/Enemy.h"
#include "headers/Spaceship.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML Window");

    space::Spaceship spaceship;
    space::Enemy enemy(300, 300);

    std::vector<space::Enemy> enemies;

    auto start = std::chrono::steady_clock::now();

    for (size_t i = 0; i < 5; ++i)
    {
        for (size_t j = 0; j < 11; ++j)
        {
            float positionX = 200 + j * (40 + 30);
            float positionY = 50 + i * (40 + 20);

            enemies.emplace_back(positionX, positionY);
        }
    }

    bool changeDirection = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        spaceship.update();

        for (space::Enemy &enemy : enemies)
        {
            if (enemy.getPosition().x >= 1240)
            {
                changeDirection = true;
                break;
            }

            if (enemy.getPosition().x <= 0)
            {
                changeDirection = true;
                break;
            }
        }

        if (changeDirection)
        {
            for (space::Enemy &enemy : enemies)
            {
                {
                    enemy.changeDirection();
                }
            }
            changeDirection = false;
        }

        auto end = std::chrono::steady_clock::now();

        float deltaTime = std::chrono::duration<float>(end - start).count();

        start = end;

        for (space::Enemy &enemy : enemies)
        {
            {
                enemy.update(deltaTime);
            }
        }

        changeDirection = false;

        window.clear();
        spaceship.render(window);

        for (const space::Enemy &enemy : enemies)
        {
            enemy.render(window);
        }

        window.display();
    }
}
