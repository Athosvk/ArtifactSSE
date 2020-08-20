#pragma once
#include <initializer_list>

namespace Artifact
{
	/// <summary>
	/// Represents a vector that tries to operate on multiple data elements in a single instruction, depending on the hardware capabilities
	/// </summary>
	template<typename taELEMENT, template<typename> typename taSIMD_VECTOR_TYPE>
	class Vector
	{
		using VectorType = taSIMD_VECTOR_TYPE<taELEMENT>;

	public:
		size_t GetSize() const
		{
			return m_Size;
		}

	private:
		size_t m_Size = 0;
	};
}
