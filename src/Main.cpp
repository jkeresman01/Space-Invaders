#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "headers/Enemy.h"
#include "headers/Spaceship.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML Window");

    space::Spaceship spaceship;
    space::Enemy enemy(300, 300);

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
        enemy.update();

        window.clear();
        spaceship.render(window);
        enemy.render(window);
        window.display();
    }
}
