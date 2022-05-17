#pragma once

#include <vector>
#include <map>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Defines.hpp"

namespace Utils
{
	sf::Vector2f normalised(const sf::Vector2f&);
	sf::Vector2f dcross(const sf::Vector2f&, const sf::Vector2f&);

	float dot(const sf::Vector2f&, const sf::Vector2f&);
	float qrsqrt(float);

	class ShapeBase
	{
		public:
			virtual sf::Vector2f getClosestVertex(sf::Vector2f);
			virtual sf::Vector2f getCenter();
	};

	class Circle : public sf::CircleShape, public ShapeBase
	{
		public:
			sf::Vector2f getClosestVertex(sf::Vector2f) override;
			sf::Vector2f getCenter() override;
	};

	class Convex : public sf::ConvexShape, public ShapeBase
	{
		public:
			sf::Vector2f getClosestVertex(sf::Vector2f) override;
			sf::Vector2f getCenter() override;
	};

	class InteractionBase
	{
		public:
			ShapeBase* int_shape;

		protected:
	};

	class CollisionBase
	{
		public:
			bool moveable = false;

			ShapeBase* col_shape;

			void addResolveVector(sf::Vector2f);

			virtual void resolve();

			virtual ~CollisionBase();

		protected:
			sf::Vector2f resolve_vector;
	};

	class DrawableBase
	{
		public:
			sf::Vector3f position;

			float r_sq = 0.f;

			virtual sf::Drawable* getDrawable();

			virtual ~DrawableBase();
	};

	class EntityBase : public CollisionBase, public InteractionBase, public DrawableBase
	{
		public:
			EntityBase(sf::Drawable* drawable);

			float mass = 1.f;
			float velocity = 0.f;


			sf::Drawable* getDrawable() override;

			~EntityBase();

		protected:
			sf::Drawable* drawable;
	};

	class AnimatedEntityBase : public EntityBase
	{
		public:
			//AnimatedEntityBase();

			void addAnimation(string name, vector< sf::Vector2i > *animation);
			void removeAnimation(string name);

		protected:
			//vector < vector < Vector2i > > animations;
			map < string, vector < sf::Vector2i > > animations;
	};
}

#include "Utils/inl/EntityBase.inl"