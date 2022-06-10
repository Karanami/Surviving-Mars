#pragma once

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

namespace utils
{
    class View
    {
        public:
            virtual void loadTextures();
            virtual void init();
            virtual void handle();
            virtual void handleEvents();
            virtual ~View() = 0;
    };
     
    class Game : public View
    {
        public:
            Game();
            Game(sf::RenderWindow* window);

            sf::RenderWindow* window;

            void loadTextures() override;
            void init() override;
            void handle() override;
            void handleEvents() override;

            void initSprites();
            void initMap();
            void handle();
            void handleEvents();

        private:
            sf::Texture* test;

            sf::Sprite* testSprite;

            std::vector<sf::Texture*> resources;
    };
}