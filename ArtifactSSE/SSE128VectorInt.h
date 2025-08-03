#pragma once

#include "SSE128Vector.h"

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

#include "SSE128VectorInt.inl"
