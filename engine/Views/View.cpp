#include "../Views.hpp"

//utils::View::View() : draw_handler(new utils::DrawingHandler(window)), coll_handler(new utils::CollisionHandler) { }
utils::View::View(sf::RenderWindow* window) : draw_handler(new utils::DrawingHandler(window)), coll_handler(new utils::CollisionHandler) { }

void utils::View::loadTextures() { return; }
void utils::View::init() { return; }
void utils::View::handle() { return; }
void utils::View::handleEvents() { return; }

utils::View::~View()
{
	for (auto& res : this->resources_spr) delete res;
	for (auto& res : this->resources_tex) delete res;
}