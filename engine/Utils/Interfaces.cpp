#include "../Utils.hpp"

using namespace sf;
using namespace std;
using namespace utils;

void CollisionBase::addResolveVector(Vector2f vec)
{
	resolve_vector += vec;
}

void CollisionBase::resolve()
{
	resolve_vector.x = 0;
	resolve_vector.y = 0;
	return;
}

CollisionBase::~CollisionBase() { };