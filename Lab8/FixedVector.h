#pragma once

#include <type_traits>
#include <cstring>

using namespace std;

namespace lab8
{
	template<typename T, size_t N>
	class FixedVector
	{
	public:
		FixedVector();
		virtual ~FixedVector();
		FixedVector(const FixedVector<T, N>& other);
		FixedVector<T, N>& operator=(const FixedVector<T, N>& other);

		bool Add(const T& t);
		bool Remove(const T& t);
		const T& Get(unsigned int index) const;
		T& operator[](unsigned int index) const;
		int GetIndex(const T& t) const;
		size_t GetSize() const;
		size_t GetCapacity() const;
	private:
		size_t mSize;
		bool mbPointer;
		T* mArray;
	};

	template<typename T, size_t N>
	FixedVector<T, N>::FixedVector()
		: mSize(0)
		, mbPointer(is_pointer<T>::value)
		, mArray(new T[N])
	{
		memset(mArray, 0, sizeof(T) * N);
	}

	template<typename T, size_t N>
	FixedVector<T, N>::~FixedVector()
	{
		if (mbPointer)
		{
			for (size_t i = 0; i < mSize; ++i)
			{
				delete mArray[i];
				mArray[i] = NULL;
			}
		}

		delete[] mArray;
	}

	template<typename T, size_t N>
	FixedVector<T, N>::FixedVector(const FixedVector<T, N>& other)
		: mSize(other.mSize)
		, mArray()
	{
		if (!mbPointer)
		{
			memcpy(mArray, other.mArray, sizeof(T) * N);
		}
		else
		{
			for (size_t i = 0; i < mSize; ++i)
			{
				mArray[i] = new T();
				*mArray[i] = *other.mArray[i];
			}
		}
	}

	template<typename T, size_t N>
	FixedVector<T, N>& FixedVector<T, N>::operator=(const FixedVector<T, N>& other)
	{
		if (this == &other)
		{
			return *this;
		}

		if (!mbPointer)
		{
			memcpy(mArray, other.mArray, sizeof(T) * N);
		}
		else
		{
			size_t i;
			for (i = 0; i < mSize; ++i)
			{
				delete mArray[i];
			}


			for (i = 0; i < other.mSize; ++i)
			{
				mArray[i] = new T();
				*mArray[i] = *other.mArray[i];
			}
		}

		mSize = other.mSize;

		return *this;
	}

	template<typename T, size_t N>
	bool FixedVector<T, N>::Add(const T& t)
	{
		if (mSize == N)
		{
			return false;
		}

		mArray[mSize++] = t;

		return true;
	}

	template<typename T, size_t N>
	bool FixedVector<T, N>::Remove(const T& t)
	{
		if (mSize == 0)
		{
			return false;
		}

		size_t removeIndex = SIZE_MAX;
		size_t i;

		for (i = 0; i < mSize; ++i)
		{
			if (mArray[i] == t)
			{
				removeIndex = i;

				if (mbPointer)
				{
					delete mArray[i];
				}
				
				break;
			}
		}

		if (removeIndex == SIZE_MAX)
		{
			return false;
		}

		for (i = removeIndex; i < mSize - 1; ++i)
		{
			mArray[i] = mArray[i + 1];
		}

		if (mSize == N)
		{
			mArray[i] = 0;
		}
		else
		{
			mArray[i] = mArray[i + 1];
		}

		--mSize;

		return true;
	}

	template<typename T, size_t N>
	const T& FixedVector<T, N>::Get(unsigned int index) const
	{
		const T& value = mArray[index];
		return value;
	}

	template<typename T, size_t N>
	T& FixedVector<T, N>::operator[](unsigned int index) const
	{
		T& value = mArray[index];
		return value;
	}
	
	template<typename T, size_t N>
	int FixedVector<T, N>::GetIndex(const T& t) const
	{
		const int FAILED_INDEX = -1;
		if (mSize == 0)
		{
			return FAILED_INDEX;
		}

		for (int i = 0; i < static_cast<int>(mSize); ++i)
		{
			if (mArray[i] == t)
			{
				return i;
			}
		}

		return FAILED_INDEX;
	}
	
	template<typename T, size_t N>
	size_t FixedVector<T, N>::GetSize() const
	{
		return mSize;
	}

	template<typename T, size_t N>
	size_t FixedVector<T, N>::GetCapacity() const
	{
		return N;
	}
}
