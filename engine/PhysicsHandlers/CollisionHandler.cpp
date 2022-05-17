#include "..\PhysicsHandlers.hpp"
#include <array>

using namespace PhysicsHandlers;
using namespace Utils;

static inline bool sameDirection(sf::Vector2f a, sf::Vector2f b)
{
	return Utils::dot(a, b) > 0;
}

static std::pair < bool, sf::Vector2f > epa(Utils::CollisionBase* a, Utils::CollisionBase* b)
{
	gjk:
	{
		int check_case = 2;

		sf::Vector2f dir_vec = b->col_shape->getCenter() - a->col_shape->getCenter();

		std::array < sf::Vector2f, 3 > vexs;

		vexs[1] = a->col_shape->getClosestVertex(dir_vec) - b->col_shape->getClosestVertex(-dir_vec);
		dir_vec = -vexs[0];
		vexs[0] = a->col_shape->getClosestVertex(dir_vec) - b->col_shape->getClosestVertex(-dir_vec);

		while (true)
		{
			sf::Vector2f buff;
			switch (check_case)
			{
				/// line case
				case 2:
				{
					if (sameDirection(vexs[1] - vexs[0], -vexs[0]))
					{
						dir_vec = dcross(vexs[1] - vexs[0], -vexs[0]);
						check_case = 3;
					}
					else
					{
						dir_vec = -vexs[1];
					}
					buff = a->col_shape->getClosestVertex(dir_vec) - b->col_shape->getClosestVertex(-dir_vec);
					vexs = { buff, vexs[0], vexs[1] };
				} break;
				/// triangle case
				case 3:
				{
					Vector2f faceAB = dcross(vexs[1] - vexs[0], -vexs[0]);
					Vector2f faceAC = dcross(vexs[2] - vexs[0], -vexs[0]);

					if (sameDirection(faceAB, -vexs[0]))
					{
						if (sameDirection(vexs[1] - vexs[0], -vexs[0]))
						{
							dir_vec = faceAB;
							buff = a->col_shape->getClosestVertex(dir_vec) - b->col_shape->getClosestVertex(-dir_vec);
						}
						else if (!sameDirection(vexs[2] - vexs[0], -vexs[0]))
						{
							dir_vec = -vexs[0];
							buff = a->col_shape->getClosestVertex(dir_vec) - b->col_shape->getClosestVertex(-dir_vec);
							vexs = { buff, vexs[1], vexs[2] };
						}
						else
						{
							goto epa;
						}
						vexs = { buff, vexs[0], vexs[1] };
					}
					else if (sameDirection(faceAC, -vexs[0]))
					{
						dir_vec = faceAC;
						buff = a->col_shape->getClosestVertex(dir_vec) - b->col_shape->getClosestVertex(-dir_vec);
						vexs = { buff, vexs[0], vexs[2] };
					}
					else
					{
						goto epa;
					}
				} break;
			}
			//idk if it works tho;
			if (dot(buff, dir_vec) <= 0) return pair < bool, Vector2f >(false, { 0, 0 });
		}
	}

	epa:
	{
		return pair < bool, Vector2f >(true, { 0, 0 });
	}
}

//-------------------------------------------------------------------------------------------------//

void CollisionHandler::addEntity(Utils::CollisionBase*shape)
{

}

void CollisionHandler::removeEntity(Utils::CollisionBase* shape)
{

}

void CollisionHandler::update(float t)
{

}

//-------------------------------------------------------------------------------------------------//

