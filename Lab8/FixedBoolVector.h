#pragma once

#include <type_traits>
#include <cstring>

namespace lab8
{
	template<size_t N>
	class FixedVector<bool, N>
	{
	public:
		FixedVector();
		virtual ~FixedVector();
		FixedVector(const FixedVector<bool, N>& bOther);
		FixedVector<bool, N>& operator=(const FixedVector<bool, N>& bOther);

		bool Add(const bool& t);
		bool Remove(const bool& t);
		const bool Get(unsigned int index) const;
		const bool operator[](unsigned int index) const;
		int GetIndex(const bool& t) const;
		size_t GetSize() const;
		size_t GetCapacity() const;
	private:
		enum 
		{
			BOOL_BYTE_SIZE = 32
		};
		typedef union 
		{
			unsigned int val;
			struct 
			{
				bool b0 : 1;
				bool b1 : 1;
				bool b2 : 1;
				bool b3 : 1;
				bool b4 : 1;
				bool b5 : 1;
				bool b6 : 1;
				bool b7 : 1;
				bool b8 : 1;
				bool b9 : 1;
				bool b10 : 1;
				bool b11 : 1;
				bool b12 : 1;
				bool b13 : 1;
				bool b14 : 1;
				bool b15 : 1;
				bool b16 : 1;
				bool b17 : 1;
				bool b18 : 1;
				bool b19 : 1;
				bool b20 : 1;
				bool b21 : 1;
				bool b22 : 1;
				bool b23 : 1;
				bool b24 : 1;
				bool b25 : 1;
				bool b26 : 1;
				bool b27 : 1;
				bool b28 : 1;
				bool b29 : 1;
				bool b30 : 1;
				bool b31 : 1;
			} bits;
		} bitflags_t;
		size_t mSize;
		bitflags_t mArray[static_cast<int>(N / BOOL_BYTE_SIZE + 1)];
	};

	template<size_t N>
	FixedVector<bool, N>::FixedVector()
		: mSize(0)
		, mArray()
	{
	}

	template<size_t N>
	FixedVector<bool, N>::~FixedVector()
	{
	}

	template<size_t N>
	FixedVector<bool, N>::FixedVector(const FixedVector<bool, N>& bOther)
		: mSize(bOther.mSize)
		, mArray()
	{
		memcpy(mArray, bOther.mArray, static_cast<int>(N / BOOL_BYTE_SIZE + 1));
	}

	template<size_t N>
	FixedVector<bool, N>& FixedVector<bool, N>::operator=(const FixedVector<bool, N>& bOther)
	{
		if (this == &bOther)
		{
			return *this;
		}

		memcpy(mArray, bOther.mArray, static_cast<int>(N / BOOL_BYTE_SIZE + 1));

		mSize = bOther.mSize;

		return *this;
	}

	template<size_t N>
	bool FixedVector<bool, N>::Add(const bool& t)
	{
		if (mSize == N)
		{
			return false;
		}

		size_t arrayIndex = 0;
		if (mSize != 0)
		{
			arrayIndex = static_cast<size_t>(mSize / BOOL_BYTE_SIZE);
		}

		bitflags_t& currentFlags = mArray[arrayIndex];
		size_t bitPoint = mSize++ % BOOL_BYTE_SIZE;
		
		unsigned int flagTrigger = true << bitPoint;
		if (t)
		{
			currentFlags.val ^= flagTrigger;
		}
		else
		{
			flagTrigger = ~flagTrigger;
			currentFlags.val &= flagTrigger;
		}

		return true;
	}

	template<size_t N>
	bool FixedVector<bool, N>::Remove(const bool& t)
	{
		if (mSize == 0)
		{
			return false;
		}

		for (size_t i = 0; i < mSize; ++i)
		{
			size_t arrayIndex = 0;
			if (mSize != 0)
			{
				arrayIndex = static_cast<size_t>(i / BOOL_BYTE_SIZE);
			}

			size_t bitPoint = i % BOOL_BYTE_SIZE;
			unsigned int flagTrigger = true << bitPoint;

			if (static_cast<bool>(mArray[arrayIndex].val & flagTrigger) == t)
			{
				for (; i < mSize - 1; ++i)
				{
					arrayIndex = static_cast<size_t>(i / BOOL_BYTE_SIZE);
					bitPoint = i % BOOL_BYTE_SIZE;
					size_t nextBitPoint = (i + 1) % BOOL_BYTE_SIZE;
					flagTrigger = true << bitPoint;
					unsigned int nextFlagTrigger = true << nextBitPoint;
					
					bool bNextValue = false;
					if (bitPoint < nextBitPoint)
					{
						bNextValue = mArray[arrayIndex].val & nextFlagTrigger;
					}
					else
					{
						arrayIndex = static_cast<size_t>((i + 1) / BOOL_BYTE_SIZE);

						bNextValue = mArray[arrayIndex].val & nextFlagTrigger;

						arrayIndex = static_cast<size_t>(i / BOOL_BYTE_SIZE);
					}

					if (bNextValue)
					{
						mArray[arrayIndex].val ^= flagTrigger;
					}
					else
					{
						flagTrigger = ~flagTrigger;
						mArray[arrayIndex].val &= flagTrigger;
					}
				}

				if (mSize == N)
				{
					arrayIndex = static_cast<size_t>(i / BOOL_BYTE_SIZE);
					bitPoint = i % BOOL_BYTE_SIZE;
					flagTrigger = true << bitPoint;
					flagTrigger = ~flagTrigger;
					mArray[arrayIndex].val &= flagTrigger;
				}
				else
				{
					arrayIndex = static_cast<size_t>(i / BOOL_BYTE_SIZE);
					bitPoint = i % BOOL_BYTE_SIZE;
					size_t nextBitPoint = (i + 1) % BOOL_BYTE_SIZE;
					flagTrigger = true << bitPoint;
					unsigned int nextFlagTrigger = true << nextBitPoint;

					bool bNextValue = false;
					if (bitPoint < nextBitPoint)
					{
						bNextValue = mArray[arrayIndex].val & nextFlagTrigger;
					}
					else
					{
						arrayIndex = static_cast<size_t>((i + 1) / BOOL_BYTE_SIZE);
						bitflags_t& nextFlags = mArray[arrayIndex];

						bNextValue = nextFlags.val & nextFlagTrigger;
					}

					if (bNextValue)
					{
						mArray[arrayIndex].val ^= flagTrigger;
					}
					else
					{
						flagTrigger = ~flagTrigger;
						mArray[arrayIndex].val &= flagTrigger;
					}
				}

				--mSize;

				return true;
			}
		}

		return false;
	}

	template<size_t N>
	const bool FixedVector<bool, N>::Get(unsigned int index) const
	{
		size_t arrayIndex = static_cast<size_t>(index / BOOL_BYTE_SIZE);

		bitflags_t currentFlags = mArray[arrayIndex];
		size_t bitPoint = index % BOOL_BYTE_SIZE;
		unsigned int flagTrigger = true << bitPoint;
		const bool bValue = currentFlags.val & flagTrigger;
		return bValue;
	}

	template<size_t N>
	const bool FixedVector<bool, N>::operator[](unsigned int index) const
	{
		return Get(index);
	}

	template<size_t N>
	int FixedVector<bool, N>::GetIndex(const bool& t) const
	{
		const int FAILED_INDEX = -1;
		if (mSize == 0)
		{
			return FAILED_INDEX;
		}

		for (int i = 0; i < static_cast<int>(mSize); ++i)
		{
			size_t arrayIndex = 0;
			if (mSize != 0)
			{
				arrayIndex = static_cast<size_t>(i / BOOL_BYTE_SIZE);
			}

			bitflags_t currentFlags = mArray[arrayIndex];
			size_t bitPoint = static_cast<size_t>(i) % BOOL_BYTE_SIZE;
			unsigned int flagTrigger = true << bitPoint;
			
			if (t)
			{
				if (currentFlags.val & flagTrigger)
				{
					return i;
				}
			}
			else
			{
				if ((currentFlags.val & flagTrigger) == false)
				{
					return i;
				}
			}
		}

		return FAILED_INDEX;
	}

	template<size_t N>
	size_t FixedVector<bool, N>::GetSize() const
	{
		return mSize;
	}

	template<size_t N>
	size_t FixedVector<bool, N>::GetCapacity() const
	{
		return N;
	}
}