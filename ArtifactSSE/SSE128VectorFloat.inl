#include "SSE128VectorFloat.h"

#include <intrin.h>

#include <array>
#include <initializer_list>

#include "ArrayUtils.h"

inline SSE128Vector<float>::SSE128Vector(const float* a_Data) :
	m_Data(_mm_loadu_ps(a_Data))
{
}

inline SSE128Vector<float>::SSE128Vector(const __m128& a_Data) :
	m_Data(a_Data)
{
}

inline SSE128Vector<float>::SSE128Vector(const std::initializer_list<float>& a_Data)
{
	// We cannot directly get the underlying data pointer of an initializer list, so we convert it to an array
	// to be safe
	alignas(16) std::array<float, 4> data = ArrayUtils<float, 4>::FromInitializerList(a_Data);
	m_Data = _mm_load_ps(data.data());
}

inline void SSE128Vector<float>::CopyTo(float* a_Target)
{
	_mm_storeu_ps(a_Target, m_Data);
}

inline SSE128Vector<float> SSE128Vector<float>::operator+(const SSE128Vector<float>& a_Other)
{
	return SSE128Vector<float>(_mm_add_ps(a_Other.m_Data, m_Data));
}

inline SSE128Vector<float> SSE128Vector<float>::operator-(const SSE128Vector<float>& a_Other)
{
	return SSE128Vector<float>(_mm_sub_ps(a_Other.m_Data, m_Data));
}

inline SSE128Vector<float> SSE128Vector<float>::operator*(const SSE128Vector<float>& a_Other)
{
	return SSE128Vector<float>(_mm_mul_ps(a_Other.m_Data, m_Data));
}

inline SSE128Vector<float> SSE128Vector<float>::operator/(const SSE128Vector<float>& a_Other)
{
	return SSE128Vector<float>(_mm_div_ps(a_Other.m_Data, m_Data));
}
