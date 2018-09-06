#pragma once
#include <array>
#include <vector>

/// <summary>
/// Represents the interface for vectors that can, but do not have to, process multiple data in a single instruction
/// </summary>
template<typename TElement>
class ISIMDVector
{	
	/// <summary>Copies the underlying data to the a, first elements of the,_Target buffer</summary>
	/// <param name="a_Target">The target buffer to copy it to. Assumes it is large enough to hold the data</param>
	virtual void CopyTo(TElement* a_Target) = 0;
};
