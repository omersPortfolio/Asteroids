#include "UnitTestPCH.h"

TEST_CASE("Vector2")
{
	SECTION("Add")
	{
		vec2 posOne = vec2(5.0f, 5.0f);
		vec2 posTwo = vec2(5.0f, 6.0f);

		CHECK(posOne + posTwo == vec2(10.0f, 11.0f));
	}

	SECTION("Subtract")
	{
		vec2 posOne = vec2(5.0f, 5.0f);
		vec2 posTwo = vec2(5.0f, 6.0f);

		CHECK(posOne - posTwo == vec2(0.0f, -1.0f));
	}
}
