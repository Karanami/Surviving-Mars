#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <Windows.h>
#include <string.h>

//#include "engine/DrawingHandlers.hpp"
#include "engine/Views.hpp"

#pragma warning(disable : 4244)

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 6;

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!", 7U, settings);
    window.setPosition(sf::Vector2i(400, 300));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Up)
                {
                    sf::View view = window.getView();
                    view.zoom(2.f);
                    //zoom_coef *= 2.f;
                    window.setView(view);
                }
                if (event.key.code == sf::Keyboard::Down)
                {
                    sf::View view = window.getView();
                    view.zoom(0.5f);
                    //zoom_coef *= 0.5;
                    window.setView(view);
                }
            }
        }
    }

    return 0;
}