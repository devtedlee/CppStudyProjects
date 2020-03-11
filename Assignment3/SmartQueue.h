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

		void Enqueue(const T number);
		T Peek() const;
		T Dequeue();
		T GetMax();
		T GetMin();
		double GetAverage() const;
		T GetSum() const;
		double GetVariance() const;
		double GetStandardDeviation() const;
		unsigned int GetCount() const;
	private:
		double mSum;
		double mDistanceSum;
		queue<T> mQueue;
	};

	template<typename T>
	SmartQueue<T>::SmartQueue()
		: mSum(0.0)
		, mDistanceSum(0.0)
	{
	}

	template<typename T>
	SmartQueue<T>::~SmartQueue()
	{
		while (!mQueue.empty())
		{
			mQueue.pop();
		}
	}

	template<typename T>
	SmartQueue<T>::SmartQueue(const SmartQueue<T>& other)
		: mSum(other.mSum)
		, mDistanceSum(other.mDistanceSum)
		, mQueue(other.mQueue)
	{
	}

	template<typename T>
	SmartQueue<T>& SmartQueue<T>::operator=(const SmartQueue<T>& other)
	{
		if (this == &other)
		{
			return *this;
		}

		while (!mQueue.empty())
		{
			mQueue.pop();
		}

		mSum = other.mSum;
		mDistanceSum = other.mDistanceSum;
		mQueue = other.mQueue;

		return *this;
	}

	template<typename T>
	void SmartQueue<T>::Enqueue(const T number)
	{
		unsigned int postCount = mQueue.size();
		double postAverage = 0.0;
		if (!mQueue.empty())
		{
			postAverage = mSum / postCount;
		}

		mQueue.push(number);

		mSum += static_cast<double>(number);
		double recentAverage = mSum / mQueue.size();
		double remainderSum = pow(recentAverage - postAverage, 2.0) * postCount;
		mDistanceSum += pow(abs(static_cast<double>(number) - recentAverage), 2.0) + remainderSum;
	}

	template<typename T>
	T SmartQueue<T>::Peek() const
	{
		// ignore empty queue case

		T value = mQueue.front();

		return value;
	}

	template<typename T>
	T SmartQueue<T>::Dequeue()
	{
		// ignore empty queue case

		unsigned int postCount = mQueue.size();
		double postAverage = mSum / postCount;

		T value = mQueue.front();
		mQueue.pop();

		if (mQueue.empty())
		{
			mSum = 0.0;
			mDistanceSum = 0.0;

			return value;
		}

		mSum -= static_cast<double>(value);
		double recentAverage = mSum / mQueue.size();
		double remainderSum = pow(recentAverage - postAverage, 2.0) * postCount;
		mDistanceSum -= pow(abs(static_cast<double>(value) - recentAverage), 2.0) - remainderSum;

		return value;
	}

	template<typename T>
	T SmartQueue<T>::GetMax()
	{
		T maxValue = numeric_limits<T>::lowest();
		queue<T> tempQueue;

		while (!mQueue.empty())
		{
			T tempValue = mQueue.front();
			mQueue.pop();
			tempQueue.push(tempValue);
			if (tempValue > maxValue)
			{
				maxValue = tempValue;
			}
		}

		while (!tempQueue.empty())
		{
			mQueue.push(tempQueue.front());
			tempQueue.pop();
		}

		return maxValue;
	}

	template<typename T>
	T SmartQueue<T>::GetMin()
	{
		T minValue = numeric_limits<T>::max();
		queue<T> tempQueue;

		while (!mQueue.empty())
		{
			T tempValue = mQueue.front();
			mQueue.pop();
			tempQueue.push(tempValue);
			if (tempValue < minValue)
			{
				minValue = tempValue;
			}
		}

		while (!tempQueue.empty())
		{
			mQueue.push(tempQueue.front());
			tempQueue.pop();
		}

		return minValue;
	}

	template<typename T>
	double SmartQueue<T>::GetAverage() const
	{
		if (mQueue.empty())
		{
			return 0.0;
		}

		return GetRoundOffTo3DecimalPlaces(mSum / mQueue.size());
	}

	template<typename T>
	T SmartQueue<T>::GetSum() const
	{
		if (mSum >= static_cast<double>(numeric_limits<T>::max()))
		{
			return numeric_limits<T>::max();
		}

		return static_cast<T>(mSum);
	}

	template<typename T>
	double SmartQueue<T>::GetVariance() const
	{
		if (mQueue.empty())
		{
			return 0.0;
		}

		return GetRoundOffTo3DecimalPlaces(mDistanceSum / mQueue.size());
	}

	template<typename T>
	double SmartQueue<T>::GetStandardDeviation() const
	{
		if (mQueue.empty())
		{
			return 0.0;
		}

		double variance = GetVariance();

		return GetRoundOffTo3DecimalPlaces(sqrt(variance));
	}

	template<typename T>
	unsigned int SmartQueue<T>::GetCount() const
	{
		return static_cast<unsigned int>(mQueue.size());
	}
}