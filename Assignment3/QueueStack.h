#pragma once

#include <cmath>
#include <limits>
#include <queue>
#include <stack>
#include "MyMath.h"

using namespace std;

namespace assignment3
{
	template<typename T>
	class QueueStack
	{
	public:
		QueueStack(unsigned int maxStackSize);
		virtual ~QueueStack();
		QueueStack(const QueueStack<T>& other);
		QueueStack<T>& operator=(const QueueStack<T>& other);

		void Enqueue(const T number);
		T Peek() const;
		T Dequeue();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		unsigned int GetCount() const;
		unsigned int GetStackCount() const;
	private:
		unsigned int mCount;
		unsigned int mMaxStackSize;
		queue<stack<T>> mQueueStack;
	};

	template<typename T>
	QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mCount(0)
		, mMaxStackSize(maxStackSize)
		, mQueueStack()
	{
	}

	template<typename T>
	QueueStack<T>::~QueueStack()
	{
	}

	template<typename T>
	QueueStack<T>::QueueStack(const QueueStack<T>& other)
		: mCount(other.mCount)
		, mMaxStackSize(other.mMaxStackSize)
		, mQueueStack(other.mQueueStack)
	{
	}

	template<typename T>
	QueueStack<T>& QueueStack<T>::operator=(const QueueStack<T>& other)
	{
		if (this == &other)
		{
			return *this;
		}

		mCount = other.mCount;
		mMaxStackSize = other.mMaxStackSize;
		mQueueStack = other.mQueueStack;

		return *this;
	}

	template<typename T>
	void QueueStack<T>::Enqueue(const T number)
	{
		queue<stack<T>> tempQueueStack;

		if (mQueueStack.empty())
		{
			mQueueStack.push(stack<T>());
		}

		while (!mQueueStack.empty())
		{
			stack<T>& frontStack = mQueueStack.front();
			if (mQueueStack.size() == 1)
			{
				if (frontStack.size() < mMaxStackSize)
				{
					frontStack.push(number);
				}
				else
				{
					tempQueueStack.push(frontStack);
					mQueueStack.pop();

					stack<T> newStack;
					newStack.push(number);
					tempQueueStack.push(newStack);

					break;
				}
			}

			tempQueueStack.push(frontStack);
			mQueueStack.pop();
		}

		while (!tempQueueStack.empty())
		{
			mQueueStack.push(tempQueueStack.front());
			tempQueueStack.pop();
		}

		++mCount;
	}

	template<typename T>
	T QueueStack<T>::Peek() const
	{
		// ignore empty queue case

		T value = mQueueStack.front().top();
		return value;
	}

	template<typename T>
	T QueueStack<T>::Dequeue()
	{
		// ignore empty queue case

		stack<T>& frontStack = mQueueStack.front();
		T value = frontStack.top();
		frontStack.pop();
		
		if (frontStack.empty())
		{
			mQueueStack.pop();
		}

		if (mQueueStack.empty())
		{
			mCount = 0;

			return value;
		}

		--mCount;

		return value;
	}

	template<typename T>
	T QueueStack<T>::GetMax()
	{
		T maxValue = numeric_limits<T>::lowest();
		queue<stack<T>> tempQueueStack;
		stack<T> tempStack;

		while (!mQueueStack.empty())
		{
			stack<T>& frontStack = mQueueStack.front();

			while (!frontStack.empty())
			{
				T tempValue = frontStack.top();
				if (tempValue > maxValue)
				{
					maxValue = tempValue;
				}

				tempStack.push(tempValue);
				frontStack.pop();
			}

			while (!tempStack.empty())
			{
				frontStack.push(tempStack.top());
				tempStack.pop();
			}

			tempQueueStack.push(frontStack);
			mQueueStack.pop();
		}

		while (!tempQueueStack.empty())
		{
			mQueueStack.push(tempQueueStack.front());
			tempQueueStack.pop();
		}

		return maxValue;
	}

	template<typename T>
	T QueueStack<T>::GetMin()
	{
		T minValue = numeric_limits<T>::max();
		queue<stack<T>> tempQueueStack;
		stack<T> tempStack;

		while (!mQueueStack.empty())
		{
			stack<T>& frontStack = mQueueStack.front();

			while (!frontStack.empty())
			{
				T tempValue = frontStack.top();
				if (tempValue < minValue)
				{
					minValue = tempValue;
				}

				tempStack.push(tempValue);
				frontStack.pop();
			}

			while (!tempStack.empty())
			{
				frontStack.push(tempStack.top());
				tempStack.pop();
			}

			tempQueueStack.push(frontStack);
			mQueueStack.pop();
		}

		while (!tempQueueStack.empty())
		{
			mQueueStack.push(tempQueueStack.front());
			tempQueueStack.pop();
		}

		return minValue;
	}

	template<typename T>
	double QueueStack<T>::GetAverage()
	{
		// ignore empty queue case
		
		T sum = GetSum();

		double average = static_cast<double>(sum) / mCount;

		return GetRoundOffTo3DecimalPlaces(average);
	}

	template<typename T>
	T QueueStack<T>::GetSum()
	{
		T sum = 0;
		queue<stack<T>> tempQueueStack;
		stack<T> tempStack;

		while (!mQueueStack.empty())
		{
			stack<T>& frontStack = mQueueStack.front();

			while (!frontStack.empty())
			{
				tempStack.push(frontStack.top());
				frontStack.pop();
			}

			while (!tempStack.empty())
			{
				T tempValue = tempStack.top();
				frontStack.push(tempValue);
				tempStack.pop();

				sum += tempValue;
			}

			tempQueueStack.push(frontStack);
			mQueueStack.pop();
		}

		while (!tempQueueStack.empty())
		{
			mQueueStack.push(tempQueueStack.front());
			tempQueueStack.pop();
		}

		return sum;
	}

	template<typename T>
	unsigned int QueueStack<T>::GetCount() const
	{
		return mCount;
	}

	template<typename T>
	unsigned int QueueStack<T>::GetStackCount() const
	{
		return static_cast<unsigned int>(mQueueStack.size());
	}
}