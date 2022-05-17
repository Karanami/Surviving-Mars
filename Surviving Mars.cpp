#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <Windows.h>
#include <string.h>

//#include "engine/Utils.hpp"
#include "engine/DrawingHandlers.hpp"

#pragma warning(disable : 4244)

using namespace std;
using namespace sf;
using namespace Utils;
using namespace DrawingHandlers;

float zoom_coef = 1.f;

int main()
{
    ContextSettings settings;
    settings.antialiasingLevel = 6;

    RenderWindow window(VideoMode(800, 600), "SFML works!", 7U, settings);
    window.setPosition(Vector2i(400, 300));
    //View def_view = window.getView();
    //window.setVerticalSyncEnabled(true);
    //window.setFramerateLimit(0);

    DrawingHandler drawing_handler(&window);

    //RectangleShape *rect1 = new RectangleShape(Vector2f(100.f, 100.f));
    //rect1->setFillColor(Color::Green);
    //rect1->setPosition(200.f, 200.f);
    //rect1->setOrigin(50.f, 50.f);
    //EntityBase< RectangleShape, DummyClass, DummyClass >* cos = new EntityBase< RectangleShape, DummyClass, DummyClass >(rect1);
    //cos->r_sq = sq(rect1->getSize().x / 2) + sq(rect1->getSize().y / 2);
    //cos->z = 0.f;
    //cos->x = 200.f;
    //cos->y = 200.f;

    //RectangleShape* rect2 = new RectangleShape(Vector2f(100.f, 100.f));
    //rect2->setFillColor(Color::Transparent);
    //rect2->setOutlineColor(Color::Red);
    //rect2->setOutlineThickness(1.f);
    //rect2->setPosition(200.f, 200.f);
    //rect2->setOrigin(50.f, 50.f);
    //EntityBase< RectangleShape, DummyClass, DummyClass >* cos2 = new EntityBase< RectangleShape, DummyClass, DummyClass >(rect2);
    //cos2->z = 0.f;
    //cos2->r_sq = sq(rect2->getSize().x / 2) + sq(rect2->getSize().y / 2);
    //cos2->x = 200.f;
    //cos2->y = 200.f;

    //RectangleShape* rect3 = new RectangleShape(Vector2f(800.f, 600.f));
    //rect3->setFillColor(Color::Transparent);
    //rect3->setOutlineColor(Color::Magenta);
    //rect3->setOutlineThickness(2.f);
    //EntityBase< RectangleShape, DummyClass, DummyClass >* cos3 = new EntityBase< RectangleShape, DummyClass, DummyClass >(rect3);
    //cos3->r_sq = sq(rect3->getSize().x / 2) + sq(rect3->getSize().y / 2);
    //cos3->x = rect3->getSize().x;
    //cos3->y = rect3->getSize().y;

    //Clock clock;

    //sf::Text text;

    //sf::Font font;
    //font.loadFromFile("fonts/arial.ttf");
    //text.setFont(font);
    //text.setCharacterSize(24);
    //text.setFillColor(sf::Color::Red);
    //text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    //text.setPosition(100.f, 100.f);

    //EntityBase< Text, DummyClass, DummyClass >* kek = new EntityBase< Text, DummyClass, DummyClass >(&text);

    //drawing_handler.addSprite(cos);
    //drawing_handler.addSprite(cos2);
    //drawing_handler.addSprite(cos3);
    //drawing_handler.addSprite(kek);

    while (window.isOpen())
    {
        //Time elapsedtime = clock.getElapsedTime();
        //clock.restart();

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) window.close();
            if (event.type == Event::MouseMoved)
            {
                //rect1->setPosition(int(event.mouseMove.x * zoom_coef + 800.f * (1.f - zoom_coef) / 2.f), int(event.mouseMove.y * zoom_coef + 600.f * (1.f - zoom_coef) / 2.f));
                //cos->x = rect1->getPosition().x;
                //cos->y = rect1->getPosition().y;
            }
            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Up)
                {
                    View view = window.getView();
                    view.zoom(2.f);
                    zoom_coef *= 2.f;
                    window.setView(view);
                }
                if (event.key.code == Keyboard::Down)
                {
                    View view = window.getView();
                    view.zoom(0.5f);
                    zoom_coef *= 0.5;
                    window.setView(view);
                }
            }
        }

        //string heh = to_string(elapsedtime.asMicroseconds());
        //text.setString(heh);
        //text.setString("ha");

        drawing_handler.update(0.f);
    }

    return 0;
}