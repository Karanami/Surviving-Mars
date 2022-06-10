#pragma once

#include <vector>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Utils.hpp"

namespace utils
{
	class DrawingHandler
	{
		public:
			DrawingHandler(sf::RenderWindow *window);

			void addSprite(utils::DrawableBase *sprite);
			void removeSprite(utils::DrawableBase *sprite);
			void update(float dt);
			void setTargetedFps(float fps);

			float getFps();

		private:
			float accumulator_t = 0.f;
			/// <summary>
			/// targeted seconds per frame
			/// </summary>
			float targeted_spf = 1 / 30.f;
			float fps = 0.f;
			/// <summary>
			/// ( invincible ) padding around the window used to dynamicly
			/// sample sprites for draw ( to include them for draw if in
			/// window's proximity )
			/// </summary>
			uint64_t window_render_proximity = 500;

			std::vector < utils::DrawableBase* > pool;
			std::vector < utils::DrawableBase* > drawing_pool;

			sf::RenderWindow *window;
	};
}