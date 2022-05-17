#include <math.h>

#include "../DrawingHandlers.hpp"

using namespace DrawingHandlers;

//-------------------------------------------------------------------------------------------------//

inline static float getDistanceSq(Utils::DrawableBase *d_b, sf::Vector2i &window_pos)
{
	return sq(window_pos.x - d_b->position.x - d_b->position.z) + sq(window_pos.y - d_b->position.y);
}

DrawingHandler::DrawingHandler(sf::RenderWindow *window)
{
	this->window = window;
	window_r_sq = sq(sqrt(sq(window->getSize().x / 2.f) + sq(window->getSize().y / 2.f)) + safe_window);
}

void DrawingHandler::addSprite(Utils::DrawableBase *sprite)
{
	pool.emplace_back(sprite);
}

void DrawingHandler::removeSprite(Utils::DrawableBase *sprite)
{
#pragma omp simd
	for (std::vector < Utils::DrawableBase* >::const_iterator s = pool.begin(); s != pool.end(); s++)
	{
		if (*s == sprite)
		{
			pool.erase(s);
			break;
		}
	}
}

void DrawingHandler::update(float t)
{
	accumulator_t += t;

	/// drawing sampling
	sf::Vector2i window_pos = window->getPosition();
#pragma omp simd
	foreach (auto draw_base in pool)
	{
		if (draw_base->r_sq + window_r_sq > getDistanceSq(draw_base, window_pos))
		{
			drawing_pool.emplace_back(draw_base);
		}
	}

	sort(drawing_pool.begin(), drawing_pool.end(), [](Utils::DrawableBase* elem1, Utils::DrawableBase* elem2) -> bool
	{
		return elem1->position.y > elem2->position.y;
	});

	window->clear();

	while (drawing_pool.size() > 0)
	{
		window->draw(*drawing_pool.back()->getDrawable());
		drawing_pool.pop_back();
	}
	window->display();
}

inline void DrawingHandler::setTargetedFps(float fps)
{
	targeted_spf = 1 / fps;
}

inline float DrawingHandler::getFps()
{
	return fps;
}

//-------------------------------------------------------------------------------------------------//