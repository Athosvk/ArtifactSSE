#include <doctest/doctest.h>

#include <ArtifactSSE/SSE128VectorInt.h>

TEST_SUITE("SSE128Vector<int> test construction")
{
	TEST_CASE("Test construction aligned")
	{
		alignas(16) int data[] = { 1, 1, 1, 1 };
		SSE128Vector<int> vector(data);

		alignas(16) int data_copy[4];
		vector.CopyTo(data_copy);
		for(int i = 0; i < 4; ++i)
		{
			REQUIRE(data[i] == data_copy[i]);
		}
	}

	TEST_CASE("Test construction unaligned")
	{
		int data[] = { 1, 1, 1, 1 };
		SSE128Vector<int> vector(data);

		int data_copy[4];
		vector.CopyTo(data_copy);

		for(int i = 0; i < 4; ++i)
		{
			REQUIRE(data[i] == data_copy[i]);
		}
	}

	TEST_CASE("Test from initializer_list")
	{
		std::initializer_list<int> data = { 1, 1, 1, 1 };
		SSE128Vector<int> vector(data);
		
		int data_copy[4];
		vector.CopyTo(data_copy);

		int i = 0;
		for(std::initializer_list<int>::const_iterator iterator(data.begin()); iterator != data.end(); ++iterator)
		{
			REQUIRE(*iterator == data_copy[i++]);
		}
	}
}

TEST_SUITE("SSE128Vector int test operations")
{
	TEST_CASE("Test addition")
	{
		SSE128Vector<int> vector({ 1, 1, 1, 1 });
		SSE128Vector<int> result = vector + vector;
		int result_data[4];
		result.CopyTo(result_data);
		for (int i = 0; i < 4; ++i)
		{
			REQUIRE(result_data[i] == 2);
		}
	}

	TEST_CASE("Test subraction")
	{
		SSE128Vector<int> vector({ 1, 1, 1, 1 });
		SSE128Vector<int> result = vector - vector;
		int result_data[4];
		result.CopyTo(result_data);
		for (int i = 0; i < 4; ++i)
		{
			REQUIRE(result_data[i] == 0);
		}
	}

	TEST_CASE("Test multiplication")
	{
		SSE128Vector<int> vector({ 2, 2, 2, 2 });
		SSE128Vector<int> result = vector * vector;
		int result_data[4];
		result.CopyTo(result_data);
		for (int i =0; i < 4; ++i)
		{
			REQUIRE(result_data[i] == 4);
		}
	}

	TEST_CASE("Test division")
	{
		SSE128Vector<int> vector({ 3, 3, 3, 3 });
		SSE128Vector<int> vector2({ 2, 2, 2, 2 });
		SSE128Vector<int> result = vector / vector;
		int result_data[4];
		result.CopyTo(result_data);
		REQUIRE(result_data[0] == 1);
		REQUIRE(result_data[1] == 1);
		REQUIRE(result_data[2] == 1);
		REQUIRE(result_data[3] == 1);
	}
}
