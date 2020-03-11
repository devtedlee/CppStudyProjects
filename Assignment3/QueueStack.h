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
	{
	}

	template<typename T>
	QueueStack<T>::~QueueStack()
	{
		while (!mQueueStack.empty())
		{
			while (!mQueueStack.front().empty())
			{
				mQueueStack.front().pop();
			}

			mQueueStack.pop();
		}
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

		while (!mQueueStack.empty())
		{
			while (!mQueueStack.front().empty())
			{
				mQueueStack.front().pop();
			}

			mQueueStack.pop();
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
			if (mQueueStack.size() == 1)
			{
				if (mQueueStack.front().size() < mMaxStackSize)
				{
					mQueueStack.front().push(number);
				}
				else
				{
					tempQueueStack.push(mQueueStack.front());
					mQueueStack.pop();

					stack<T> newStack;
					newStack.push(number);
					tempQueueStack.push(newStack);
					newStack.pop();

					break;
				}
			}

			tempQueueStack.push(mQueueStack.front());
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

		T value = mQueueStack.front().top();
		mQueueStack.front().pop();
		
		if (mQueueStack.front().empty())
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

		while (!mQueueStack.empty())
		{
			stack<T> tempStack;
			stack<T> tempFrontStack = mQueueStack.front();

			while (!mQueueStack.front().empty())
			{
				T tempValue = mQueueStack.front().top();
				tempStack.push(tempValue);
				if (tempValue > maxValue)
				{
					maxValue = tempValue;
				}
				mQueueStack.front().pop();
			}

			while (!tempStack.empty())
			{
				mQueueStack.front().push(tempStack.top());
				tempStack.pop();
			}

			tempQueueStack.push(mQueueStack.front());
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

		while (!mQueueStack.empty())
		{
			stack<T> tempStack;

			while (!mQueueStack.front().empty())
			{
				T tempValue = mQueueStack.front().top();
				mQueueStack.front().pop();
				tempStack.push(tempValue);
				if (tempValue < minValue)
				{
					minValue = tempValue;
				}
			}

			while (!tempStack.empty())
			{
				mQueueStack.front().push(tempStack.top());
				tempStack.pop();
			}

			tempQueueStack.push(mQueueStack.front());
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
		
		double sum = 0;
		queue<stack<T>> tempQueueStack;
		
		while (!mQueueStack.empty())
		{
			stack<T> tempStack;

			while (!mQueueStack.front().empty())
			{
				tempStack.push(mQueueStack.front().top());
				mQueueStack.front().pop();
			}

			while (!tempStack.empty())
			{
				T tempValue = tempStack.top();
				sum += static_cast<double>(tempValue);

				mQueueStack.front().push(tempValue);
				tempStack.pop();
			}

			tempQueueStack.push(mQueueStack.front());
			mQueueStack.pop();
		}

		while (!tempQueueStack.empty())
		{
			mQueueStack.push(tempQueueStack.front());
			tempQueueStack.pop();
		}

		double average = sum / mCount;

		if (average >= static_cast<double>(numeric_limits<T>::max()))
		{
			average = static_cast<double>(numeric_limits<T>::max());
		}

		return GetRoundOffTo3DecimalPlaces(average);
	}

	template<typename T>
	T QueueStack<T>::GetSum()
	{
		double doubleSum = 0.0;
		T sum = 0;
		queue<stack<T>> tempQueueStack;

		while (!mQueueStack.empty())
		{
			stack<T> tempStack;

			while (!mQueueStack.front().empty())
			{
				tempStack.push(mQueueStack.front().top());
				mQueueStack.front().pop();
			}

			while (!tempStack.empty())
			{
				T tempValue = tempStack.top();

				if (doubleSum + static_cast<double>(tempValue) >= static_cast<double>(numeric_limits<T>::max()))
				{
					sum = numeric_limits<T>::max();
				}
				else
				{
					sum += tempValue;
				}
				doubleSum += static_cast<double>(tempValue);

				mQueueStack.front().push(tempValue);
				tempStack.pop();
			}

			tempQueueStack.push(mQueueStack.front());
			mQueueStack.pop();
		}

		while (!tempQueueStack.empty())
		{
			mQueueStack.push(tempQueueStack.front());
			tempQueueStack.pop();
		}

		return static_cast<T>(sum);
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