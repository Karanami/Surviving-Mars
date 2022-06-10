#include "../Utils.hpp"

using namespace utils;

sf::Vector3f DrawableBase::getPosition3d()
{
	auto vec2 = this->getPosition();
	return { vec2.x, vec2.y, this->z };
}

void DrawableBase::setPosition3d(sf::Vector3f vec3)
{
	this->z = vec3.z;
	this->setPosition(vec3.x, vec3.y);
}

void DrawableBase::setPosition3d(float x, float y, float z)
{
	this->z = z;
	this->setPosition(x, y);
}

void DrawableBase::setPosition3d(sf::Vector2f vec2, float z)
{
	this->z = z;
	this->setPosition(vec2);
}

uint64_t DrawableBase::getSafeProximitySq()
{
	return sq(this->safe_proximity);
}