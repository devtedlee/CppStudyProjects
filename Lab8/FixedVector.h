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
		size_t mCount;
		bool mbPointer;
		T mArray[N];
	};

	template<typename T, size_t N>
	FixedVector<T, N>::FixedVector()
		: mCount(0)
		, mbPointer(is_pointer<T>::value)
		, mArray()
	{
	}

	template<typename T, size_t N>
	FixedVector<T, N>::~FixedVector()
	{
		if (mbPointer)
		{
			for (size_t i = 0; i < mCount; ++i)
			{
				delete reinterpret_cast<void*>(mArray[i]);
				mArray[i] = NULL;
			}
		}
	}

	template<typename T, size_t N>
	FixedVector<T, N>::FixedVector(const FixedVector<T, N>& other)
		: mCount(other.mCount)
		, mArray()
	{
		if (!mbPointer)
		{
			memcpy(mArray, other.mArray, sizeof(T) * N);
		}
		else
		{
			for (size_t i = 0; i < mCount; ++i)
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
			for (size_t i = 0; i < N; ++i)
			{
				if (i < mCount)
				{
					delete reinterpret_cast<void*>(mArray[i]);
				}

				if (i < other.mCount)
				{
					mArray[i] = new T();
					*mArray[i] = *other.mArray[i];
				}
				else
				{
					mArray[i] = 0;
				}
			}
		}

		mCount = other.mCount;

		return *this;
	}

	template<typename T, size_t N>
	bool FixedVector<T, N>::Add(const T& t)
	{
		if (mCount == N)
		{
			return false;
		}

		mArray[mCount] = t;
		++mCount;

		return true;
	}

	template<typename T, size_t N>
	bool FixedVector<T, N>::Remove(const T& t)
	{
		if (mCount == 0)
		{
			return false;
		}

		size_t removeIndex = SIZE_MAX;
		size_t i;

		for (i = 0; i < mCount; ++i)
		{
			if (mArray[i] == t)
			{
				removeIndex = i;

				if (mbPointer)
				{
					delete reinterpret_cast<void*>(mArray[i]);
				}
			}
		}

		if (removeIndex == SIZE_MAX)
		{
			return false;
		}

		for (i = removeIndex; i < mCount - 1; ++i)
		{
			mArray[i] = mArray[i + 1];
		}

		if (mCount == N)
		{
			mArray[i] = 0;
		}
		else
		{
			mArray[i] = mArray[i + 1];
		}

		--mCount;

		return true;
	}

	template<typename T, size_t N>
	const T& FixedVector<T, N>::Get(unsigned int index) const
	{
		return T();
	}

	template<typename T, size_t N>
	T& FixedVector<T, N>::operator[](unsigned int index) const
	{
		return T();
	}
	
	template<typename T, size_t N>
	int FixedVector<T, N>::GetIndex(const T& t) const
	{
		return 0;
	}
	
	template<typename T, size_t N>
	size_t FixedVector<T, N>::GetSize() const
	{
		return 0U;
	}

	template<typename T, size_t N>
	size_t FixedVector<T, N>::GetCapacity() const
	{
		return 0U;
	}
}
