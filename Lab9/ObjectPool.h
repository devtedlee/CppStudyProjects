#pragma once

#include <queue>

namespace lab9
{
	template<typename T>
	class ObjectPool
	{
	public:
		ObjectPool(size_t maxPoolSize);
		~ObjectPool();
		ObjectPool(ObjectPool<T>& other) = delete;
		ObjectPool<T>& operator=(ObjectPool<T>& other) = delete;

		T* Get();
		void Return(T* tP);
		size_t GetFreeObjectCount() const;
		size_t GetMaxFreeObjectCount() const;
	private:
		size_t mMaxPoolSize;
		std::queue<T*> mObjects;
	};

	template<typename T>
	ObjectPool<T>::ObjectPool(size_t maxPoolSize)
		: mMaxPoolSize(maxPoolSize)
		, mObjects()
	{
	}

	template<typename T>
	ObjectPool<T>::~ObjectPool()
	{
		size_t objCount = mObjects.size();
		for (size_t i = 0; i < objCount; ++i)
		{
			T* frontObj = mObjects.front();
			mObjects.pop();
			delete frontObj;
		}
	}

	template<typename T>
	T* ObjectPool<T>::Get()
	{
		if (mObjects.empty())
		{
			return new T;
		}

		T* returnObj = mObjects.front();
		mObjects.pop();

		return returnObj;
	}

	template<typename T>
	void ObjectPool<T>::Return(T* tP)
	{
		if (mObjects.size() >= mMaxPoolSize)
		{
			delete tP;
			return;
		}

		mObjects.push(tP);
	}

	template<typename T>
	size_t ObjectPool<T>::GetFreeObjectCount() const
	{
		return mObjects.size();
	}

	template<typename T>
	size_t ObjectPool<T>::GetMaxFreeObjectCount() const
	{
		return mMaxPoolSize;
	}
}