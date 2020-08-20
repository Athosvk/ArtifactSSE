#include <doctest/doctest.h>

#include <ArtifactSSE/Vector.h>
#include <ArtifactSSE/SSE128Vector.h>

TEST_SUITE("Test vector operations")
{
	TEST_CASE("Test construction")
	{
		Artifact::Vector<int, SSE128Vector> vector;
		REQUIRE(vector.GetSize() == 0);
	}
}