#include "GamePCH.h"

#include "Math.h"

Random Math::s_Random = Random();

float Math::DegreesToRadians(float degrees)
{
	return degrees * 0.01745329251f;
}

float Math::RadiansToDegrees(float radians)
{
	return radians * 57.2957795131f;
}

vec2 Math::CalculateClosesPointOnLine(const sf::VertexArray& segment, const vec2& point)
{
	return vec2(0, 0);
}

float Math::Clamp(float value, float min, float max)
{
	if (value < min)
	{
		return min;
	}

	if (value > max)
	{
		return max;
	}

	return value;
}

sf::Vector2f Math::Clamp(const sf::Vector2f& value, const sf::Vector2f& min, const sf::Vector2f& max)
{
	if (value.x < min.x || value.y < min.y)
	{
		return min;
	}

	if (value.x > max.x || value.y > max.y)
	{
		return max;
	}

	return value;
}

int Math::Clamp(int value, int min, int max)
{
	if (value < min)
	{
		return min;
	}

	if (value > max)
	{
		return max;
	}

	return value;
}

int Math::RandomIntInRange(int min, int max)
{
	return s_Random.RandomIntInRange(min, max);
}

float Math::RandomFloatInRange(float min, float max)
{
	return s_Random.RandomFloatInRange(min, max);
}

bool Math::RandomChance(unsigned int chance)
{
	unsigned int random = rand() % chance;
	return random == 0;
}

