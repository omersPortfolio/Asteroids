#include <Catch2/catch.hpp>
#include <Core/Math.h>

TEST_CASE("Math")
{
	SECTION("Int Clamp")
	{
		int a = 10;
		int result = Math::Clamp(a + 20, 0, 29);
		CHECK(result == 29);
	}

	SECTION("Float Clamp")
	{
		float a = 10;
		float result = Math::Clamp(a + 20.0f, 0.0f, 29.9f);
		CHECK(result == 29.9f);
	}
}
