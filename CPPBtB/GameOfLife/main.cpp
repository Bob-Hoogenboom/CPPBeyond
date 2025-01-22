#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameRules.h"


int main()
{
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({ 500, 500 }), "Lekker voor God Spelen");
    srand(time(NULL));
    window->setFramerateLimit(60);

    GameRules gameOfLife(window);

    while(window->isOpen())
    {
        sf::Event event;
        while(window->pollEvent(event))
        {
            if(event.type == sf::Event::Closed || event.type == sf::Keyboard::Escape) window->close();
        }

        window->clear();

        gameOfLife.update();
        gameOfLife.draw(window);

        window->display();
    }
}