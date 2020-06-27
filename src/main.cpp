#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

#include "spdlog/spdlog.h"

int main()
{
    auto logger = spdlog::default_logger();
    logger->info("Logger initialized!");

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape  shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}