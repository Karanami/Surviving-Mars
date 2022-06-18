#include <math.h>

#include "../DrawingHandlers.hpp"

//-------------------------------------------------------------------------------------------------//

static uint64_t getDistanceSq(utils::DrawableBase *d_b, sf::Vector2i &window_pos)
{
	return sq(uint64_t(window_pos.x) - uint64_t(d_b->getPosition3d().x) - uint64_t(d_b->getPosition3d().z)) + sq(uint64_t(window_pos.y) - uint64_t(d_b->getPosition3d().y));
}

utils::DrawingHandler::DrawingHandler(sf::RenderWindow *window)
{
	this->window = window;
}

void utils::DrawingHandler::add(utils::DrawableBase *sprite)
{
	pool.emplace_back(sprite);
}

void utils::DrawingHandler::remove(utils::DrawableBase *sprite)
{
#pragma omp simd
	for (auto s = pool.begin(); s != pool.end(); s++)
	{
		if (*s == sprite)
		{
			pool.erase(s);
			break;
		}
	}
}

void utils::DrawingHandler::update(float dt)
{
	accumulator_t += dt;

	/// drawing sampling
	sf::Vector2i window_pos = window->getPosition();
#pragma omp simd
	for (auto draw_base : pool)
	{
		if (draw_base->getSafeProximitySq() + sq(this->window_render_proximity) > getDistanceSq(draw_base, window_pos))
		{
			drawing_pool.emplace_back(draw_base);
		}
	}

	sort(drawing_pool.begin(), drawing_pool.end(), [](utils::DrawableBase* elem1, utils::DrawableBase* elem2) -> bool
	{
		return elem1->getPosition3d().y > elem2->getPosition3d().y;
	});

	window->clear();
	while (drawing_pool.size() > 0)
	{
		window->draw(*drawing_pool.back());
		drawing_pool.pop_back();
	}
	window->display();
}

void utils::DrawingHandler::setTargetedFps(float fps)
{
	targeted_spf = 1 / fps;
}

float utils::DrawingHandler::getFps()
{
	return fps;
}

//-------------------------------------------------------------------------------------------------//