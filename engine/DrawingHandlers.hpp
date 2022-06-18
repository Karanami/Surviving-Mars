#pragma once

#include <vector>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Utils.hpp"

namespace utils
{
	class RenderingHandler
	{
		private:
			/// <summary>
			/// ( invincible ) padding around the window used to dynamicly
			/// sample sprites for draw ( to include them for draw if in
			/// window's proximity )
			/// </summary>
			uint64_t window_render_proximity = 500;

			sf::RenderWindow* window;
	};

	class DrawingHandler
	{
		public:
			DrawingHandler(sf::RenderWindow *window);

			void add(utils::DrawableBase *sprite);
			void remove(utils::DrawableBase *sprite);
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

			std::vector < utils::DrawableBase* > pool;
			std::vector < utils::DrawableBase* > drawing_pool;

			sf::RenderWindow *window;
	};

	class AnimationHandler
	{
		public:
			AnimationHandler(sf::RenderWindow* window);

			void add(utils::AnimatedEntityBase* sprite);
			void remove(utils::AnimatedEntityBase* sprite);
			void update(float dt);

		private:
			float accumulator_t = 0.f;

			std::vector < utils::AnimatedEntityBase* > pool;
			std::vector < utils::AnimatedEntityBase* > drawing_pool;
	};
}