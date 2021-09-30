#include "GamePCH.h"

#include "Random.h"

Random::Random()
	: m_MersenneTwister(std::random_device{}())
{

}

Random::Random(int seed)
	: m_MersenneTwister(seed)
{

}

int Random::RandomInt()
{
	std::uniform_int_distribution<int> distribution(0, 5);
	return distribution(m_MersenneTwister);
}

int Random::RandomIntInRange(int min, int max)
{
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(m_MersenneTwister);
}

float Random::RandomFloatInRange(float min, float max)
{
	std::uniform_real_distribution<float> distribution(min, max);
	return distribution(m_MersenneTwister);
}
