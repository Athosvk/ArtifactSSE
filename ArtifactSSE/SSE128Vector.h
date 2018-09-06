#pragma once
#include <initializer_list>

#include "ISIMDVector.h"
#include "ConfigurationMacros.h"

#if defined(_MSVC)
#include <xmmintrin.h>
#include <emmintrin.h>
#else
union __m128;
union __m128i;
#endif

/// <summary>
/// Represents a 128 bit SSE (Streaming SIMD Extensions) vector
/// </summary>
template<typename TElement>
class SSE128Vector
{
	SSE128Vector()
	{
		static_assert("No SIMD available for given type");
	}
};
