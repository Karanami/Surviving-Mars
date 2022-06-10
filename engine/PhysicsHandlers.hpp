#pragma once

#include <vector>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Utils.hpp"
#include "Defines.hpp"

namespace utils
{
	class CollisionHandler
	{
		public:
			void addEntity(utils::CollisionBase*shape);
			void removeEntity(utils::CollisionBase*shape);
			void update(float t);
		
		protected:
			std::vector < utils::CollisionBase* > pool;
	};
}