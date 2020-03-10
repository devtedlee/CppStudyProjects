#pragma once

#include <cmath>
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

		void Push(const T& number);
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
		unsigned int mCount;
		stack<T>* mStack;
	};

	template<typename T>
	SmartStack<T>::SmartStack()
		: mCount(0)
		, mStack(new stack<T>)
	{
	}

	template<typename T>
	SmartStack<T>::~SmartStack()
	{
		delete mStack;
	}

	template<typename T>
	SmartStack<T>::SmartStack(const SmartStack<T>& other)
		: mCount(other.mCount)
	{
		delete mStack;
		mStack = new stack<T>(*other.mStack);
	}

	template<typename T>
	SmartStack<T>& SmartStack<T>::operator=(const SmartStack<T>& other)
	{
		if (this == &other)
		{
			return *this;
		}

		mCount = other.mCount;
		
		delete mStack;
		mStack = new stack<T>(*other.mStack);

		return *this;
	}

	template<typename T>
	void SmartStack<T>::Push(const T& number)
	{
		mStack->push(number);
		++mCount;
	}

	template<typename T>
	T SmartStack<T>::Pop()
	{
		// ignore empty queue case

		T value = mStack->top();

		mStack->pop();
		--mCount;

		return value;
	}

	template<typename T>
	T SmartStack<T>::Peek() const
	{
		// ignore empty queue case

		T value = mStack->top();

		return value;
	}

	template<typename T>
	T SmartStack<T>::GetMax() const
	{
		T maxValue = numeric_limits<T>::min();
		stack<T> tempStack;
		T tempValue = 0;

		while (!mStack->empty())
		{
			tempValue = mStack->top();
			mStack->pop();
			tempStack.push(tempValue);
			if (tempValue > maxValue)
			{
				maxValue = tempValue;
			}
		}

		while (!tempStack.empty())
		{
			mStack->push(tempStack.top());
			tempStack.pop();
		}

		return maxValue;
	}

	template<typename T>
	T SmartStack<T>::GetMin() const
	{
		T minValue = numeric_limits<T>::max();
		stack<T> tempStack;
		T tempValue = 0;

		while (!mStack->empty())
		{
			tempValue = mStack->top();
			mStack->pop();
			tempStack.push(tempValue);
			if (tempValue < minValue)
			{
				minValue = tempValue;
			}
		}

		while (!tempStack.empty())
		{
			mStack->push(tempStack.top());
			tempStack.pop();
		}

		return minValue;
	}

	template<typename T>
	double SmartStack<T>::GetAverage() const
	{
		T sum = GetSum();

		return GetRoundOffTo3DecimalPlaces(static_cast<double>(sum) / static_cast<double>(mCount));
	}

	template<typename T>
	T SmartStack<T>::GetSum() const
	{
		double sum = 0.0;
		stack<T> tempStack;
		T tempValue = 0;

		while (!mStack->empty())
		{
			tempValue = mStack->top();
			mStack->pop();
			tempStack.push(tempValue);

			sum += static_cast<double>(tempValue);
		}

		while (!tempStack.empty())
		{
			mStack->push(tempStack.top());
			tempStack.pop();
		}

		return static_cast<T>(sum);
	}

	template<typename T>
	double SmartStack<T>::GetVariance() const
	{
		double distanceSum = 0.0;
		double average = GetAverage();

		stack<T> tempStack;
		T tempValue = 0;

		while (!mStack->empty())
		{
			tempValue = mStack->top();
			mStack->pop();
			tempStack.push(tempValue);

			distanceSum += pow(abs(static_cast<double>(tempValue) - average), 2.0);
		}

		while (!tempStack.empty())
		{
			mStack->push(tempStack.top());
			tempStack.pop();
		}

		return GetRoundOffTo3DecimalPlaces(distanceSum / static_cast<double>(mCount));
	}

	template<typename T>
	double SmartStack<T>::GetStandardDeviation() const
	{
		double variance = GetVariance();

		return GetRoundOffTo3DecimalPlaces(sqrt(variance));
	}

	template<typename T>
	unsigned int SmartStack<T>::GetCount() const
	{
		return mCount;
	}
}