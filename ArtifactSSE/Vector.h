#pragma once
#include <initializer_list>

namespace Artifact
{
	/// <summary>
	/// Represents a vector that can, possibly, operate on multiple data elements in a single instruction
	/// </summary>
	template<template<typename> typename taSIMD_VECTOR_TYPE, typename taELEMENT>
	class SIMDVector
	{
		using VectorType = taSIMD_VECTOR_TYPE<taELEMENT>;

	public:
		size_t GetSize() const
		{
			return static_cast<VectorType*>(this)->GetSize();
		}
	};
}
