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
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		double GetVariance();
		double GetStandardDeviation();
		unsigned int GetCount() const;
	private:
		unsigned int mCount;
		double mSum;
		double mAverage;
		double mDistanceSum;
		stack<T> mStack;
		stack<T> mMaxStack;
		stack<T> mMinStack;
	};

	template<typename T>
	SmartStack<T>::SmartStack()
		: mCount(0)
		, mSum(0.0)
		, mAverage(0.0)
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
		: mCount(other.mCount)
		, mSum(other.mSum)
		, mAverage(other.mAverage)
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

		mCount = other.mCount;
		mSum = other.mSum;
		mAverage = other.mAverage;
		mDistanceSum = other.mDistanceSum;
		mStack = other.mStack;
		mMaxStack = other.mMaxStack;
		mMinStack = other.mMinStack;

		return *this;
	}

	template<typename T>
	void SmartStack<T>::Push(const T number)
	{
		double postAverage = mAverage;
		unsigned int postCount = mCount;

		mStack.push(number);

		++mCount;
		mSum += static_cast<double>(number);
		mAverage = mSum / mCount;
		double remainderSum = pow(mAverage - postAverage, 2.0) * postCount;
		mDistanceSum += pow(abs(static_cast<double>(number) - mAverage), 2.0) + remainderSum;

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

		double postAverage = mAverage;
		unsigned int postCount = mCount;

		T value = mStack.top();
		mStack.pop();
		--mCount;

		if (mStack.empty())
		{
			mCount = 0U;
			mSum = 0.0;
			mAverage = 0.0;
			mDistanceSum = 0.0;

			return value;
		}

		mSum -= static_cast<double>(value);
		mAverage = mSum / mCount;
		double remainderSum = pow((mAverage - postAverage), 2.0) * postCount;
		mDistanceSum -= pow(abs(static_cast<double>(value) - mAverage), 2.0) - remainderSum;

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
	T SmartStack<T>::GetMax()
	{
		T maxValue = mMaxStack.top();

		return maxValue;
	}

	template<typename T>
	T SmartStack<T>::GetMin()
	{
		T minValue = mMinStack.top();

		return minValue;
	}

	template<typename T>
	double SmartStack<T>::GetAverage()
	{
		// ignore empty queue case

		return GetRoundOffTo3DecimalPlaces(mAverage);
	}

	template<typename T>
	T SmartStack<T>::GetSum()
	{
		if (mSum >= static_cast<double>(numeric_limits<T>::max()))
		{
			return numeric_limits<T>::max();
		}

		return static_cast<T>(mSum);
	}

	template<typename T>
	double SmartStack<T>::GetVariance()
	{
		if (mStack.empty())
		{
			return 0.0;
		}

		return GetRoundOffTo3DecimalPlaces(mDistanceSum / mCount);
	}

	template<typename T>
	double SmartStack<T>::GetStandardDeviation()
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
		return mCount;
	}
}