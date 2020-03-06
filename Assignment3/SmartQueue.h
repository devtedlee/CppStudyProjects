#pragma once

#include <limits>
#include <queue>

using namespace std;

namespace assignment3
{
	template<typename T>
	class SmartQueue
	{
	public:
		SmartQueue();
		virtual ~SmartQueue();

		void Enqueue(T number);
		T Peek() const;
		T Dequeue();
		T GetMax() const;
		T GetMin() const;
		double GetAverage() const;
		T GetSum() const;
		double GetVariance() const;
		double GetStandardDeviation() const;
		unsigned int GetCount() const;
	private:
		unsigned int mCount;
		queue<T>* mQueue;
	};

	template<typename T>
	SmartQueue<T>::SmartQueue()
		: mCount(0)
		, mQueue(new queue<T>)
	{
	}

	template<typename T>
	SmartQueue<T>::~SmartQueue()
	{
		delete mQueue;
	}

	template<typename T>
	void SmartQueue<T>::Enqueue(T number)
	{
	}

	template<typename T>
	T SmartQueue<T>::Peek() const
	{
		// ignore empty queue case

		T value = mQueue->front();

		return value;
	}

	template<typename T>
	T SmartQueue<T>::Dequeue()
	{
		T a = 0;

		return a;
	}

	template<typename T>
	T SmartQueue<T>::GetMax() const
	{
		T a = 0;

		return a;
	}

	template<typename T>
	T SmartQueue<T>::GetMin() const
	{
		T a = 0;

		return a;
	}

	template<typename T>
	double SmartQueue<T>::GetAverage() const
	{
		return 0.0;
	}

	template<typename T>
	T SmartQueue<T>::GetSum() const
	{
		T a = 0;

		return a;
	}

	template<typename T>
	double SmartQueue<T>::GetVariance() const
	{
		return 0.0;
	}

	template<typename T>
	double SmartQueue<T>::GetStandardDeviation() const
	{
		return 0.0;
	}

	template<typename T>
	unsigned int SmartQueue<T>::GetCount() const
	{
		return 0U;
	}
}