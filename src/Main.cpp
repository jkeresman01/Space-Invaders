#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "headers/ResourceManager.h"
#include "headers/Spaceship.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML Window");

    space::ResourceManager resourceManager;
    space::Spaceship spaceship;

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

        window.clear();
        spaceship.render(window);
        window.display();
    }
}
