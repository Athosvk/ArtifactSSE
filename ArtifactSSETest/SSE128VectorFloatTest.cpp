#include <doctest/doctest.h>

#include <ArtifactSSE/SSE128VectorFloat.h>

TEST_SUITE("SSE128Vector float test construction")
{
	TEST_CASE("Test construction aligned")
	{
		alignas(16) float data[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		SSE128Vector<float> vector(data);

		alignas(16) float data_copy[4];
		vector.CopyTo(data_copy);
		for(int i = 0; i < 4; ++i)
		{
			REQUIRE(data[i] == data_copy[i]);
		}
	}

	TEST_CASE("Test construction unaligned")
	{
		float data[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		SSE128Vector<float> vector(data);

		float data_copy[4];
		vector.CopyTo(data_copy);
		for(int i = 0; i < 4; ++i)
		{
			REQUIRE(data[i] == data_copy[i]);
		}
	}

	TEST_CASE("Test from initializer_list")
	{
		std::initializer_list<float> data = { 1, 1, 1, 1 };
		SSE128Vector<float> vector(data);
		
		float data_copy[4];
		vector.CopyTo(data_copy);

		int i = 0;
		for(std::initializer_list<float>::const_iterator iterator(data.begin()); iterator != data.end(); ++iterator)
		{
			REQUIRE(*iterator == data_copy[i++]);
		}
	}
}

TEST_SUITE("SSE128Vector float test operations")
{
	TEST_CASE("Test addition")
	{
		SSE128Vector<float> vector({ 1.0f, 1.0f, 1.0f, 1.0f });
		SSE128Vector<float> result = vector + vector;
		float result_data[4];
		result.CopyTo(result_data);
		for(int i = 0; i < 4; ++i)
		{
			REQUIRE(result_data[i] == doctest::Approx(2.0f));
		}
	}

	TEST_CASE("Test subraction")
	{
		SSE128Vector<float> vector({ 1.0f, 1.0f, 1.0f, 1.0f });
		SSE128Vector<float> result = vector - vector;
		float result_data[4];
		result.CopyTo(result_data);
		for(int i = 0; i < 4; ++i)
		{
			REQUIRE(result_data[i] == doctest::Approx(0.0f));
		}
	}

	TEST_CASE("Test multiplication")
	{
		SSE128Vector<float> vector({ 2.0f, 2.0f, 2.0f, 2.0f });
		SSE128Vector<float> result = vector * vector;
		float result_data[4];
		result.CopyTo(result_data);
		for (int i = 0; i < 4; ++i)
		{
			REQUIRE(result_data[i] == doctest::Approx(4.0f));
		}
	}

	TEST_CASE("Test division")
	{
		SSE128Vector<float> vector({ 2.0f, 2.0f, 2.0f, 2.0f });
		SSE128Vector<float> result = vector / vector;
		float result_data[4];
		result.CopyTo(result_data);
		for (int i = 0; i < 4; ++i)
		{
			REQUIRE(result_data[i] == doctest::Approx(1.0f));
		}
	}
}