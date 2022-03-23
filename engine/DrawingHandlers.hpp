#include <vector>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Defines.hpp"

namespace DrawingHandlers
{
	using namespace sf;
	using namespace std;

	class DrawingHandler
	{
		public:
			DrawingHandler(RenderWindow ref window);

			void addSprite(Sprite ref sprite);
			void removeSprite(Sprite ref sprite);

		private:
			vector < const Sprite* > drawing_pool;

			const RenderWindow* window;
	};
}