#pragma once

#include <vector>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Utils.hpp"

namespace DrawingHandlers
{
	class DrawingHandler
	{
		public:
			DrawingHandler(sf::RenderWindow *window);

			void addSprite(Utils::DrawableBase *sprite);
			void removeSprite(Utils::DrawableBase *sprite);
			void update(float t);
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
			float safe_window = 500.f;
			float window_r_sq = 0.f;

			std::vector < Utils::DrawableBase* > pool;
			std::vector < Utils::DrawableBase* > drawing_pool;

			sf::RenderWindow *window;
	};
}