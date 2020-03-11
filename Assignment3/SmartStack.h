#pragma once

#include <cmath>
#include <limits>
#include <stack>
#include "MyMath.h"

using namespace std;

namespace assignment3
{
	template<typename T>
	class SmartStack
	{
	public:
		SmartStack();
		virtual ~SmartStack();
		SmartStack(const SmartStack<T>& other);
		SmartStack& operator=(const SmartStack<T>& other);

		void Push(const T number);
		T Pop();
		T Peek() const;
		T GetMax() const;
		T GetMin() const;
		double GetAverage() const;
		T GetSum() const;
		double GetVariance() const;
		double GetStandardDeviation() const;
		unsigned int GetCount() const;
	private:
		double mSum;
		double mDistanceSum;
		stack<T> mStack;
		stack<T> mMaxStack;
		stack<T> mMinStack;
	};

	template<typename T>
	SmartStack<T>::SmartStack()
		: mSum(0.0)
		, mDistanceSum(0.0)
	{
		mMaxStack.push(numeric_limits<T>::lowest());
		mMinStack.push(numeric_limits<T>::max());
	}

	template<typename T>
	SmartStack<T>::~SmartStack()
	{
	}

	template<typename T>
	SmartStack<T>::SmartStack(const SmartStack<T>& other)
		: mSum(other.mSum)
		, mDistanceSum(other.mDistanceSum)
		, mStack(other.mStack)
		, mMaxStack(other.mMaxStack)
		, mMinStack(other.mMinStack)
	{
	}

	template<typename T>
	SmartStack<T>& SmartStack<T>::operator=(const SmartStack<T>& other)
	{
		if (this == &other)
		{
			return *this;
		}

		mSum = other.mSum;
		mDistanceSum = other.mDistanceSum;
		mStack = other.mStack;
		mMaxStack = other.mMaxStack;
		mMinStack = other.mMinStack;

		return *this;
	}

	template<typename T>
	void SmartStack<T>::Push(const T number)
	{
		unsigned int postCount = mStack.size();
		double postAverage = 0.0;
		if (!mStack.empty())
		{
			postAverage = mSum / postCount;
		}

		mStack.push(number);

		mSum += static_cast<double>(number);
		double recentAverage = mSum / mStack.size();
		double remainderSum = pow(recentAverage - postAverage, 2.0) * postCount;
		mDistanceSum += pow(abs(static_cast<double>(number) - recentAverage), 2.0) + remainderSum;

		if (mMaxStack.top() <= number)
		{
			mMaxStack.push(number);
		}

		if (mMinStack.top() >= number)
		{
			mMinStack.push(number);
		}
	}

	template<typename T>
	T SmartStack<T>::Pop()
	{
		// ignore empty queue case

		unsigned int postCount = mStack.size();
		double postAverage = mSum / postCount;

		T value = mStack.top();
		mStack.pop();
		
		if (mStack.empty())
		{
			mSum = 0.0;
			mDistanceSum = 0.0;
			mMaxStack.pop();
			mMinStack.pop();

			return value;
		}

		mSum -= static_cast<double>(value);
		double recentAverage = mSum / mStack.size();
		double remainderSum = pow(recentAverage - postAverage, 2.0) * postCount;
		mDistanceSum -= pow(abs(static_cast<double>(value) - recentAverage), 2.0) - remainderSum;

		if (mMaxStack.top() == value)
		{
			mMaxStack.pop();
		}

		if (mMinStack.top() == value)
		{
			mMinStack.pop();
		}

		return value;
	}

	template<typename T>
	T SmartStack<T>::Peek() const
	{
		// ignore empty queue case

		T value = mStack.top();

		return value;
	}

	template<typename T>
	T SmartStack<T>::GetMax() const
	{
		T maxValue = mMaxStack.top();

		return maxValue;
	}

	template<typename T>
	T SmartStack<T>::GetMin() const
	{
		T minValue = mMinStack.top();

		return minValue;
	}

	template<typename T>
	double SmartStack<T>::GetAverage() const
	{
		// ignore empty queue case

		return GetRoundOffTo3DecimalPlaces(mSum / mStack.size());
	}

	template<typename T>
	T SmartStack<T>::GetSum() const
	{
		if (mSum >= static_cast<double>(numeric_limits<T>::max()))
		{
			return numeric_limits<T>::max();
		}

		return static_cast<T>(mSum);
	}

	template<typename T>
	double SmartStack<T>::GetVariance() const
	{
		if (mStack.empty())
		{
			return 0.0;
		}

		return GetRoundOffTo3DecimalPlaces(mDistanceSum / mStack.size());
	}

	template<typename T>
	double SmartStack<T>::GetStandardDeviation() const
	{
		if (mStack.empty())
		{
			return 0.0;
		}

		double variance = GetVariance();

		return GetRoundOffTo3DecimalPlaces(sqrt(variance));
	}

	template<typename T>
	unsigned int SmartStack<T>::GetCount() const
	{
		return mStack.size();
	}
}