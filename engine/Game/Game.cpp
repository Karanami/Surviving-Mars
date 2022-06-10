#include "../Game.hpp"
#include "../Utils.hpp"
#include "../MapUtils.hpp"

const std::string path_to_texture_folder = "../../textures/";

static std::string getTexturePath(const std::string texture)
{
	return path_to_texture_folder + texture;
}

utils::Game::Game() : window(new sf::RenderWindow(sf::VideoMode(800, 600), "---")) { };
utils::Game::Game(sf::RenderWindow* window) : window(window) { };

void utils::Game::loadTextures()
{
	this->test->loadFromFile(getTexturePath("test/skrzynka"));
}

void utils::Game::init()
{
	this->testSprite->setTexture(*this->test);
}

void utils::Game::handle()
{
	this->window->draw(*this->testSprite);
}

void utils::Game::handleEvents()
{
	sf::Event event;
	while (this->window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed) this->window->close();
	}
}

void utils::Game::initSprites()
{

}

void utils::Game::initMap()
{

}

void utils::Game::handle()
{

}

void utils::Game::handleEvents()
{

}