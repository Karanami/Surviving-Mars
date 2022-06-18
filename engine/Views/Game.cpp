#include "../Views.hpp"

const std::string path_to_texture_folder = "../../textures/";

static std::string getTexturePath(const std::string texture)
{
	return path_to_texture_folder + texture;
}

utils::Game::Game() : window(new sf::RenderWindow(sf::VideoMode(800, 600), "---")), View(this->window) { };
utils::Game::Game(sf::RenderWindow* window) : window(window), View(window) { };

void utils::Game::loadTextures()
{
	this->test->loadFromFile(getTexturePath("test/skrzynka"));
}

void utils::Game::init()
{
	this->loadTextures();
	this->initSprites();
	this->initMap();
}

void utils::Game::handle()
{
	float dt = this->clock.getElapsedTime().asSeconds();
	this->clock.restart();
	this->coll_handler->update(dt);
	this->draw_handler->update(dt);
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
	this->testSprite->setTexture(*this->test);
}

void utils::Game::initMap()
{
	return;
}

utils::Game::~Game() { };