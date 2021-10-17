#pragma once

#include <Core/Random.h>
#include <Core/Vector.h>

namespace sf
{
	class VertexArray;
}



struct Math
{
	static float DegreesToRadians(float degrees);
	static float RadiansToDegrees(float radians);

	vec2 CalculateClosesPointOnLine(const sf::VertexArray& segment, const vec2& point);

	static float Clamp(float value, float min, float max);
	static int Clamp(int value, int min, int max);

	static int RandomIntInRange(int min, int max);
	static float RandomFloatInRange(float min, float max);
	
	static bool RandomChance(unsigned int chance);
	
private:
	static Random s_Random;
};
