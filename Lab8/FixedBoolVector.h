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
			unsigned int Val;
			struct 
			{
				bool bBit0 : 1;
				bool bBit1 : 1;
				bool bBit2 : 1;
				bool bBit3 : 1;
				bool bBit4 : 1;
				bool bBit5 : 1;
				bool bBit6 : 1;
				bool bBit7 : 1;
				bool bBit8 : 1;
				bool bBit9 : 1;
				bool bBit10 : 1;
				bool bBit11 : 1;
				bool bBit12 : 1;
				bool bBit13 : 1;
				bool bBit14 : 1;
				bool bBit15 : 1;
				bool bBit16 : 1;
				bool bBit17 : 1;
				bool bBit18 : 1;
				bool bBit19 : 1;
				bool bBit20 : 1;
				bool bBit21 : 1;
				bool bBit22 : 1;
				bool bBit23 : 1;
				bool bBit24 : 1;
				bool bBit25 : 1;
				bool bBit26 : 1;
				bool bBit27 : 1;
				bool bBit28 : 1;
				bool bBit29 : 1;
				bool bBit30 : 1;
				bool bBit31 : 1;
			} Bits;
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
			currentFlags.Val ^= flagTrigger;
		}
		else
		{
			flagTrigger = ~flagTrigger;
			currentFlags.Val &= flagTrigger;
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

			if (static_cast<bool>(mArray[arrayIndex].Val & flagTrigger) == t)
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
						bNextValue = mArray[arrayIndex].Val & nextFlagTrigger;
					}
					else
					{
						arrayIndex = static_cast<size_t>((i + 1) / BOOL_BYTE_SIZE);

						bNextValue = mArray[arrayIndex].Val & nextFlagTrigger;

						arrayIndex = static_cast<size_t>(i / BOOL_BYTE_SIZE);
					}

					if (bNextValue)
					{
						mArray[arrayIndex].Val ^= flagTrigger;
					}
					else
					{
						flagTrigger = ~flagTrigger;
						mArray[arrayIndex].Val &= flagTrigger;
					}
				}

				if (mSize == N)
				{
					arrayIndex = static_cast<size_t>(i / BOOL_BYTE_SIZE);
					bitPoint = i % BOOL_BYTE_SIZE;
					flagTrigger = true << bitPoint;
					flagTrigger = ~flagTrigger;
					mArray[arrayIndex].Val &= flagTrigger;
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
						bNextValue = mArray[arrayIndex].Val & nextFlagTrigger;
					}
					else
					{
						arrayIndex = static_cast<size_t>((i + 1) / BOOL_BYTE_SIZE);
						bitflags_t& nextFlags = mArray[arrayIndex];

						bNextValue = nextFlags.Val & nextFlagTrigger;
					}

					if (bNextValue)
					{
						mArray[arrayIndex].Val ^= flagTrigger;
					}
					else
					{
						flagTrigger = ~flagTrigger;
						mArray[arrayIndex].Val &= flagTrigger;
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
		const bool bValue = currentFlags.Val & flagTrigger;
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
				if (currentFlags.Val & flagTrigger)
				{
					return i;
				}
			}
			else
			{
				if ((currentFlags.Val & flagTrigger) == false)
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