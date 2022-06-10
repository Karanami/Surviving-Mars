#pragma once

#include <vector>
#include <map>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Defines.hpp"

namespace utils
{
	sf::Vector2f normalised(sf::Vector2f);
	sf::Vector2f dcross(sf::Vector2f, sf::Vector2f);

	float dot(sf::Vector2f, sf::Vector2f);
	float qsqrt(float);

	enum class CollsionPriority
	{
		Moveable,
		Entities,
		Unmoveable
	};

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

			virtual ~InteractionBase();

		protected:
	};

	class CollisionBase
	{
		public:
			//bool moveable = false;

			ShapeBase* col_shape;

			void addResolveVector(sf::Vector2f);

			virtual void resolve();

			virtual ~CollisionBase();

		protected:
			sf::Vector2f resolve_vector;
	};

	class DrawableBase : public sf::Sprite 
	{
		public:
			sf::Vector3f getPosition3d();
			void setPosition3d(sf::Vector3f);
			void setPosition3d(float, float, float);
			void setPosition3d(sf::Vector2f, float);

			uint64_t getSafeProximitySq();

		protected:
			float z;
			uint64_t safe_proximity = 10;
	};

	class EntityBase : public CollisionBase, public InteractionBase, public DrawableBase
	{
		public:
			EntityBase();

			float mass = 1.f;
			float velocity = 0.f;

			sf::Vector2f direction;

		protected:
	};

	class AnimatedEntityBase : public EntityBase
	{
		public:
			//AnimatedEntityBase();

			void addAnimation(std::string name, std::vector< sf::Vector2i > *animation);
			void removeAnimation(std::string name);

		protected:
			//vector < vector < Vector2i > > animations;
			std::map < std::string, std::vector < sf::Vector2i > > animations;
	};
}

#include "utils/inl/EntityBase.inl"