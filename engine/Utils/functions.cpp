#include "../Utils.hpp"

float utils::qsqrt(float number)
{
    // DOOM's quick sqrt function, see 
    long i;
    float x, y;
    const float threehalfs = 1.5F;

    x = number * 0.5F;
    y = number;
    i = *(long*)&y;
    i = 0x5f3759df - (i >> 1);
    y = *(float*)&i;
    y = y * (threehalfs - (x * y * y));

    return y;
}

sf::Vector2f utils::normalised(const sf::Vector2f vec)
{
	float t = qsqrt(sq(vec.x) + sq(vec.y));
    return { vec.x * t, vec.y * t };
}

sf::Vector2f utils::dcross(const sf::Vector2f a, const sf::Vector2f b)
{
    float z = a.x * b.y - b.x * a.y;
    return { a.y * z, - (a.x * z) };
}

//sf::Vector2f utils::normdcross(const sf::Vector2f& a, const sf::Vector2f& b)
//{
//    float z = a.x * b.y - b.x * a.y;
//    return normalised({ a.y * z, -(a.x * z) });
//}

float utils::dot(const sf::Vector2f vec1, const sf::Vector2f vec2)
{
	return vec1.x * vec2.y + vec1.y * vec2.x;
}
