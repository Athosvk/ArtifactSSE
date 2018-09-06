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

/// <summary>
/// Represents a 128 bit SSE (Streaming SIMD Extensions) vector
/// </summary>
template<>
class SSE128Vector<float> : public ISIMDVector<float>
{
private:	
	/// <summary>The underlying data</summary>
	__m128 m_Data;

public:
	/// <summary>Initializes a new instance of the <see cref="SSE128Vector"/> class.</summary>
	/// <param name="a_Data">The data to initialise the vector with, assuming it contains at least 4 floats. Preferably 16-byte aligned</param>
	SSE128Vector(const float* a_Data);	

	/// <summary>Initializes a new instance of the <see cref="SSE128Vector"/> class.</summary>
	/// <param name="a_Data">The data to initialise the vector with</param>
	SSE128Vector(const __m128& a_Data);

	/// <summary>Initializes a new instance of the <see cref="SSE128Vector"/> class.</summary>
	/// <param name="a_Data">The data to initialise the vector with, assuming it contains at least 4 floats</param>
	SSE128Vector(const std::initializer_list<float>& a_Data);

	void CopyTo(float* a_Target) override;	
	SSE128Vector<float> operator+(const SSE128Vector<float>& a_Other);
	SSE128Vector<float> operator-(const SSE128Vector<float>& a_Other);
	SSE128Vector<float> operator*(const SSE128Vector<float>& a_Other);
	SSE128Vector<float> operator/(const SSE128Vector<float>& a_Other);
};

/// <summary>
/// Represents a 128 bit SSE (Streaming SIMD Extensions) vector
/// </summary>
template<>
class SSE128Vector<int> : public ISIMDVector<int>
{
private:	
	/// <summary>The underlying data</summary>
	__m128i m_Data;

public:
	/// <summary>Initializes a new instance of the <see cref="SSE128Vector"/> class.</summary>
	SSE128Vector();

	/// <summary>Initializes a new instance of the <see cref="SSE128Vector"/> class.</summary>
	/// <param name="a_Data">The data to initialise the vector with, assuming it contains at least 4 integers. Preferably 16-byte aligned</param>
	SSE128Vector(const int* a_Data);

	/// <summary>Initializes a new instance of the <see cref="SSE128Vector"/> class.</summary>
	/// <param name="a_Data">The data to initialise the vector with</param>
	SSE128Vector(const __m128i& a_Data);

	/// <summary>Initializes a new instance of the <see cref="SSE128Vector"/> class.</summary>
	/// <param name="a_Data">The data to initialise the vector with, assuming it contains at least 4 floats</param>
	SSE128Vector(const std::initializer_list<int>& a_Data);

	void CopyTo(int* a_Target) override;
	SSE128Vector<int> operator+(const SSE128Vector<int>& a_Other);
	SSE128Vector<int> operator-(const SSE128Vector<int>& a_Other);
	SSE128Vector<int> operator*(const SSE128Vector<int>& a_Other);
	SSE128Vector<int> operator/(const SSE128Vector<int>& a_Other);
};


#include "SSE128Vector.inl"
