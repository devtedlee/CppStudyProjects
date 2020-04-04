#pragma once

#include <memory>

namespace lab11
{
	template<typename T>
	class Storage
	{
	public:
		Storage(unsigned int length);
		Storage(unsigned int length, const T& initialValue);
		Storage(const Storage<T>& other);
		Storage(Storage<T>&& other);
		~Storage();
		Storage<T>& operator=(const Storage<T>& other);
		Storage<T>& operator=(Storage<T>&& other);

		bool Update(unsigned int index, const T& data);
		const std::unique_ptr<T[]>& GetData() const;
		unsigned int GetSize() const;

	private:
		unsigned int mLength;
		std::unique_ptr<T[]> mArray;
	};

	template<typename T>
	Storage<T>::Storage(unsigned int length)
		: mLength(length)
	{
		mArray.reset(new T[mLength]);
		memset(mArray.get(), 0, sizeof(T) * mLength);
	}

	template<typename T>
	Storage<T>::Storage(unsigned int length, const T& initialValue)
		: mLength(length)
	{
		mArray.reset(new T[mLength]);
		T* mArrayP = mArray.get();
		for (unsigned int i = 0; i < mLength; ++i)
		{
			mArrayP[i] = initialValue;
		}
	}

	template<typename T>
	Storage<T>::Storage(const Storage<T>& other)
		: mLength(other.mLength)
	{
		mArray.reset(new T[mLength]);
		memcpy(mArray.get(), other.mArray.get(), sizeof(T) * mLength);
	}

	template<typename T>
	Storage<T>::Storage(Storage<T>&& other)
		: mLength(other.mLength)
		, mArray(std::move(other.mArray))
	{
		other.mLength = 0;
		other.mArray.reset(nullptr);
	}

	template<typename T>
	Storage<T>::~Storage()
	{
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(const Storage<T>& other)
	{
		if (this == &other)
		{
			return *this;
		}

		mLength = other.mLength;
		mArray.reset(new T[mLength]);
		memcpy(mArray.get(), other.mArray.get(), sizeof(T) * mLength);

		return *this;
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(Storage<T>&& other)
	{
		if (this == &other)
		{
			return *this;
		}

		mLength = other.mLength;
		mArray.reset(std::move(other.mArray));

		other.mLength = 0;
		other.mArray.reset(nullptr);

		return *this;
	}

	template<typename T>
	bool Storage<T>::Update(unsigned int index, const T& data)
	{
		if (index > mLength - 1)
		{
			return false;
		}

		T* mArrayP = mArray.get() + index;
		*mArrayP = data;

		return true;
	}

	template<typename T>
	const std::unique_ptr<T[]>& Storage<T>::GetData() const
	{
		return std::move(mArray);
	}

	template<typename T>
	unsigned int Storage<T>::GetSize() const
	{
		return mLength;
	}
}
