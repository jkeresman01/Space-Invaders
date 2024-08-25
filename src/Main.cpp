#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "headers/Enemy.h"
#include "headers/Spaceship.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML Window");

    space::Spaceship spaceship;
    space::Enemy enemy(300, 300);

    std::vector<space::Enemy> enemies;

    for(size_t i = 0; i < 5; ++i)
    {
        for(size_t j = 0; j < 11; ++j)
        {
            float positionX = 200 + j * (40 + 30);
            float positionY = 50 + i * (40 + 20);

            enemies.emplace_back(positionX, positionY);
        }
    }

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

        for(space::Enemy& enemy : enemies)
        {
            enemy.update();
        }

        window.clear();
        spaceship.render(window);

        for(const space::Enemy& enemy : enemies)
        {
            enemy.render(window);
        }

        window.display();
    }
}
