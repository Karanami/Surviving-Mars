#include <vector>
#include <map>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Defines.hpp"

namespace Utils
{
	using namespace sf;
	using namespace std;

	class IntersectionBase
	{
		public:
			virtual Vector2f getCollisionClosestVertex(Vector2f);
			virtual Vector2f getInteractionClosestVertex(Vector2f);
	};

	template < class CollisionnShape, class InteractionShape >
	class EntityBase : public IntersectionBase
	{
		public:
			EntityBase(const Sprite ref sprite);

			float x = 0;
			float y = 0;
			float z = 0;

			CollisionnShape* col_shape;
			InteractionShape* int_shape;

		 	Sprite* sprite;

			virtual void clear();
	};

	template < class CollisionnShape, class InteractionShape >
	class AnimatedEntityBase : public EntityBase < CollisionnShape, InteractionShape >
	{
		public:
			AnimatedEntityBase();

			void addAnimation(string name, vector< Vector2i > ref animation);
			void removeAnimation(string name);

		protected:
			//vector < vector < Vector2i > > animations;
			map < string, vector < Vector2i > > animations;
	};
}