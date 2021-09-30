#pragma once

#include "Random.h"
#include "vec2.h"

#define M_PI 3.1415926535897932384626433832795f

const float FEQUALEPSILON = 0.00001f;

struct Math
{
	static float DegreesToRadians(float degrees);
	static float RadiansToDegrees(float radians);

	vec2 CalculateClosesPointOnLine(const sf::VertexArray& segment, const vec2& point);

	static float Clamp(float value, float min, float max);
	static int Clamp(int value, int min, int max);
	static sf::Vector2f Clamp(const sf::Vector2f& value, const sf::Vector2f& min, const sf::Vector2f& max);

	static int RandomIntInRange(int min, int max);
	static float RandomFloatInRange(float min, float max);
	
	static bool RandomChance(unsigned int chance);
	
private:
	static Random s_Random;
};
