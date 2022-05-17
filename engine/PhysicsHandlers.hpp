#pragma once

#include <vector>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Utils.hpp"
#include "Defines.hpp"

namespace PhysicsHandlers
{
	using namespace sf;
	using namespace std;
	using namespace Utils;

	class CollisionHandler
	{
		public:
			void addEntity(Utils::CollisionBase*shape);
			void removeEntity(Utils::CollisionBase*shape);
			void update(float t);
		
		protected:
			vector < Utils::CollisionBase* > pool;
	};
}