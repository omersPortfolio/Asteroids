#pragma once

#include <random>

class Random
{
public:
	Random();
	Random(int seed);

	int RandomInt();

	int RandomIntInRange(int min, int max);

	float RandomFloatInRange(float min, float max);

	template<typename T>
	T RandomValueInRange(T min, T max)
	{
		std::uniform_real_distribution<T> distribution(min, max);
		return distribution(m_MersenneTwister);
	}

private:
	std::mt19937 m_MersenneTwister;
};