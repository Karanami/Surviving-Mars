#include "../Utils.hpp"

using namespace Utils;

sf::Vector2f Circle::getClosestVertex(sf::Vector2f vec)
{
	return this->getRadius() * normalised(vec);
}

sf::Vector2f Circle::getCenter()
{
	return this->getPosition();
}

sf::Vector2f Convex::getClosestVertex(sf::Vector2f vec)
{
	int num = this->getPointCount();

	float max = -INFINITY;
	
	sf::Vector2f max_vex;

//#pragma omp simd
	for(int i = 0; i < num; i++)
	{
		sf::Vector2f buff_vex = this->getPoint(i);
		float buff_dot = Utils::dot(normalised(vec), normalised(buff_vex));
		if (buff_dot > max)
		{
			max = buff_dot;
			max_vex = buff_vex;
		}
	}
	return max_vex;
}

sf::Vector2f Convex::getCenter()
{
	return this->getPosition();
}