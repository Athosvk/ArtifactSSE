#pragma once

#include "SSE128Vector.h"

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

#include "SSE128VectorFloat.inl"
