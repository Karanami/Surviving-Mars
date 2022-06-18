#pragma once

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

#include "DrawingHandlers.hpp"
#include "EntitiesHandlers.hpp"
#include "PhysicsHandlers.hpp"
#include "MapUtils.hpp"
#include "Utils.hpp"

namespace utils
{
    class View
    {
        public:
            View(sf::RenderWindow*);

            DrawingHandler* draw_handler;

            CollisionHandler* coll_handler;

            sf::Clock clock;

            std::vector<sf::Texture*> resources_tex;
            std::vector<sf::Sprite*> resources_spr;

            virtual void loadTextures();
            virtual void init();
            virtual void handle();
            virtual void handleEvents();

            virtual ~View();
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

            ~Game();

        private:
            sf::Texture* test;

            sf::Sprite* testSprite;
    };
}