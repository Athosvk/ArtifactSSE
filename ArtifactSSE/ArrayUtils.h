#pragma once
#include <array>
#include <initializer_list>
#include <cassert>

/// <summary>
/// Provides several utility functions for interacting with std::array
/// </summary>
template<class TElement, size_t TSize>
class ArrayUtils
{
public:
	ArrayUtils() = delete;
	
	/// <summary>Constructs an std::array from an std::initializer_list</summary>
	/// <param name="a_Elements">The initializer list to construct the std::array from, assuming it is of sufficient size</param>
	/// <returns>The std::array constructed from the std::initializer_list</returns>
	static std::array<TElement, TSize> FromInitializerList(const std::initializer_list<TElement>& a_Elements)
	{
		std::array<TElement, TSize> data;
		std::initializer_list<TElement>::const_iterator iterator = a_Elements.begin();
		for(size_t i = 0; i < TSize; ++i)
		{
			data[i] = *(iterator++);
		}
		return data;
	}
};
