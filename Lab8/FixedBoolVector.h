#pragma once

#include "FixedVector.h"

namespace lab8
{
	template<size_t N>
	class FixedVector<bool, N>
	{
		FixedVector();
		virtual ~FixedVector();
		FixedVector(const FixedVector<bool, N>& other);
		FixedVector<bool, N>& operator=(const FixedVector<bool, N>& other);

		bool Add(const bool t);
		bool Remove(const bool t);
		const bool& Get(unsigned int index) const;
		bool& operator[](unsigned int index) const;
		int GetIndex(const bool& t) const;
		size_t GetSize() const;
		size_t GetCapacity() const;
	private:
		size_t mCount;
		bool mArray[N];
	};
}