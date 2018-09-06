#include "SSE128Vector.h"

#include <intrin.h>

#ifdef SSE_INITIALIZER_LIST_CONSTRUCTION
#include <array>
#include <initializer_list>

#include "ArrayUtils.h"
#endif /* SSE_INITIALIZER_LIST_CONSTRUCTION */

inline SSE128Vector<float>::SSE128Vector(const float* a_Data) :
	m_Data(_mm_loadu_ps(a_Data))
{
}

inline SSE128Vector<float>::SSE128Vector(const __m128& a_Data) :
	m_Data(a_Data)
{
}

#ifdef SSE_INITIALIZER_LIST_CONSTRUCTION
inline SSE128Vector<float>::SSE128Vector(const std::initializer_list<float>& a_Data)
{
	// We cannot directly get the underlying data pointer of an initializer list, so we convert it to an array
	// to be safe
	alignas(16) std::array<float, 4> data = ArrayUtils<float, 4>::FromInitializerList(a_Data);
	m_Data = _mm_load_ps(data.data());
}
#endif /* SSE_INITIALIZER_LIST_CONSTRUCTION */

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

inline SSE128Vector<int>::SSE128Vector(const int* a_Data) :
	m_Data(_mm_lddqu_si128(reinterpret_cast<const __m128i*>(a_Data)))
{
}

inline SSE128Vector<int>::SSE128Vector(const __m128i& a_Data) :
	m_Data(a_Data)
{
}

#ifdef SSE_INITIALIZER_LIST_CONSTRUCTION
inline SSE128Vector<int>::SSE128Vector(const std::initializer_list<int>& a_Data)
{
	alignas(16) std::array<int, 4> data = ArrayUtils<int, 4>::FromInitializerList(a_Data);
	m_Data = _mm_load_si128(reinterpret_cast<__m128i*>(data.data()));
}
#endif /* SSE_INITIALIZER_LIST_CONSTRUCTION */

inline void SSE128Vector<int>::CopyTo(int* a_Target)
{
	_mm_storeu_si128(reinterpret_cast<__m128i*>(a_Target), m_Data);
}

inline SSE128Vector<int> SSE128Vector<int>::operator+(const SSE128Vector<int>& a_Other)
{
	return SSE128Vector<int>(_mm_add_epi32(a_Other.m_Data, m_Data));
}

inline SSE128Vector<int> SSE128Vector<int>::operator-(const SSE128Vector<int>& a_Other)
{
	return SSE128Vector<int>(_mm_sub_epi32(a_Other.m_Data, m_Data));
}

inline SSE128Vector<int> SSE128Vector<int>::operator*(const SSE128Vector<int>& a_Other)
{
#if SSE_MAJOR >= 4
	return SSE128Vector<int>(_mm_mullo_epi32(a_Other.m_Data, m_Data));
#else
	// Multiplies the elements at the even indices ([0, 2]) of the vector
	__m128i even_multiplication_result(_mm_mul_epu32(a_Other.m_Data, m_Data));

	// Multiplies the elements at the odd indicies ([1, 3]) of the vector through shifting the data to the even indices ([0, 2])
	__m128i odd_multiplication_result(_mm_mul_epu32(_mm_srli_si128(a_Other.m_Data, sizeof(int)), _mm_srli_si128(m_Data, sizeof(int))));

	// Combine the results by shifting them appropriately to the first 64 bits, then interleave
	// them.
	// E.g. even_multiplication_result has value [0, 1, 0, 1] and
	// odd_multiplication_result [1, 0, 1, 0]. 
	// We shift these results to become [0, 0, 1, 1] for both, then combine the results by interleaving each, to become
	// [odd_multiplication_result[1], even_multiplication_result[1], odd_multiplication_result[0], even_multiplication_result[0]]
	// off the data after it was shifted
	return SSE128Vector<int>(_mm_unpacklo_epi32(_mm_shuffle_epi32(even_multiplication_result, _MM_SHUFFLE(0, 0, 2, 0)),
		_mm_shuffle_epi32(odd_multiplication_result, _MM_SHUFFLE(0, 0, 2, 0))));
#endif
}
