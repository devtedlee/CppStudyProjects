#pragma once

#include <cmath>
#include <limits>
#include <queue>
#include "MyMath.h"

using namespace std;

namespace assignment3
{
	template<typename T>
	class SmartQueue
	{
	public:
		SmartQueue();
		virtual ~SmartQueue();
		SmartQueue(const SmartQueue<T>& other);
		SmartQueue& operator=(const SmartQueue<T>& other);

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
	SmartQueue<T>::SmartQueue(const SmartQueue<T>& other)
		: mCount(other.mCount)
	{
		delete mQueue;
		mQueue = new stack<T>(*other.mQueue);
	}

	template<typename T>
	SmartQueue<T>& SmartQueue<T>::operator=(const SmartQueue<T>& other)
	{
		if (this == &other)
		{
			return *this;
		}

		mCount = other.mCount;

		delete mQueue;
		mQueue = new stack<T>(*other.mQueue);

		return *this;
	}

	template<typename T>
	void SmartQueue<T>::Enqueue(T number)
	{
		mQueue->push(number);
		++mCount;
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
		// ignore empty queue case

		T value = mQueue->front();

		mQueue->pop();
		--mCount;

		return value;
	}

	template<typename T>
	T SmartQueue<T>::GetMax() const
	{
		T maxValue = numeric_limits<T>::lowest();
		queue<T> tempQueue;

		while (!mQueue->empty())
		{
			T tempValue = mQueue->front();
			mQueue->pop();
			tempQueue.push(tempValue);
			if (tempValue > maxValue)
			{
				maxValue = tempValue;
			}
		}

		while (!tempQueue.empty())
		{
			mQueue->push(tempQueue.front());
			tempQueue.pop();
		}

		return maxValue;
	}

	template<typename T>
	T SmartQueue<T>::GetMin() const
	{
		T minValue = numeric_limits<T>::max();
		queue<T> tempQueue;

		while (!mQueue->empty())
		{
			T tempValue = mQueue->front();
			mQueue->pop();
			tempQueue.push(tempValue);
			if (tempValue < minValue)
			{
				minValue = tempValue;
			}
		}

		while (!tempQueue.empty())
		{
			mQueue->push(tempQueue.front());
			tempQueue.pop();
		}

		return minValue;
	}

	template<typename T>
	double SmartQueue<T>::GetAverage() const
	{
		if (mQueue->empty())
		{
			return 0.0;
		}

		T sum = GetSum();

		return GetRoundOffTo3DecimalPlaces(static_cast<double>(sum) / static_cast<double>(mCount));
	}

	template<typename T>
	T SmartQueue<T>::GetSum() const
	{
		if (mQueue->empty())
		{
			return 0.0;
		}

		double sum = 0.0;
		queue<T> tempQueue;
		T tempValue = 0;

		while (!mQueue->empty())
		{
			tempValue = mQueue->front();
			mQueue->pop();
			tempQueue.push(tempValue);

			sum += static_cast<double>(tempValue);
		}

		while (!tempQueue.empty())
		{
			mQueue->push(tempQueue.front());
			tempQueue.pop();
		}

		return static_cast<T>(sum);
	}

	template<typename T>
	double SmartQueue<T>::GetVariance() const
	{
		if (mQueue->empty())
		{
			return 0.0;
		}

		double distanceSum = 0.0;
		double average = GetAverage();

		queue<T> tempQueue;
		T tempValue = 0;

		while (!mQueue->empty())
		{
			tempValue = mQueue->front();
			mQueue->pop();
			tempQueue.push(tempValue);

			distanceSum += pow(abs(static_cast<double>(tempValue) - average), 2.0);
		}

		while (!tempQueue.empty())
		{
			mQueue->push(tempQueue.front());
			tempQueue.pop();
		}

		return GetRoundOffTo3DecimalPlaces(distanceSum / static_cast<double>(mCount));
	}

	template<typename T>
	double SmartQueue<T>::GetStandardDeviation() const
	{
		if (mQueue->empty())
		{
			return 0.0;
		}

		double variance = GetVariance();

		return GetRoundOffTo3DecimalPlaces(sqrt(variance));
	}

	template<typename T>
	unsigned int SmartQueue<T>::GetCount() const
	{
		return mCount;
	}
}