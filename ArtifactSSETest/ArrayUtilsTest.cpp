#include <doctest/doctest.h>

#include <ArtifactSSE/ArrayUtils.h>

TEST_SUITE("ArrayUtils::FromInitializerList")
{
	TEST_CASE("ArrayUtils::FromInitializerList test single element construction")
	{
		std::array<int, 1> data;
		data[0] = 1;
		REQUIRE(ArrayUtils<int, 1>::FromInitializerList({ data[0] }) == data);
	}

	TEST_CASE("ArrayUtils::FromInitializerList test multiple element construction")
	{
		std::array<int, 4> data;
		data[0] = 1;
		data[1] = 1;
		data[2] = 1;
		data[3] = 1;

		REQUIRE(ArrayUtils<int, 4>::FromInitializerList({ data[0], data[1], data[2], data[3] }) == data);
	}
}