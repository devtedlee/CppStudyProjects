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
		QueueStack(QueueStack<T>& other);
		QueueStack<T>& operator=(QueueStack<T>& other);

		void Enqueue(T number);
		T Peek() const;
		T Dequeue();
		T GetMax();
		T GetMin();
		double GetAverage() const;
		T GetSum() const;
		unsigned int GetCount() const;
		unsigned int GetStackCount() const;
	private:
		unsigned int mCount;
		unsigned int mMaxStackSize;
		double mSum;
		queue<stack<T>*> mQueueStack;
	};

	template<typename T>
	QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mCount(0)
		, mMaxStackSize(maxStackSize)
		, mSum(0.0)
	{
	}

	template<typename T>
	QueueStack<T>::~QueueStack()
	{
		stack<T>* tempStackP;
		while (!mQueueStack.empty())
		{
			tempStackP = mQueueStack.front();
			mQueueStack.pop();

			delete tempStackP;
			tempStackP = nullptr;
		}
	}

	template<typename T>
	QueueStack<T>::QueueStack(QueueStack<T>& other)
		: mCount(other.mCount)
		, mMaxStackSize(other.mMaxStackSize)
		, mSum(other.mSum)
	{
		queue<stack<T>*> tempQueueStack;

		while (!other.mQueueStack.empty())
		{
			stack<T>* tempStackP = other.mQueueStack.front();
			other.mQueueStack.pop();

			tempQueueStack.push(tempStackP);
			mQueueStack.push(new stack<T>(*tempStackP));
		}

		while (!tempQueueStack.empty())
		{
			other.mQueueStack.push(tempQueueStack.front());
			tempQueueStack.pop();
		}
	}

	template<typename T>
	QueueStack<T>& QueueStack<T>::operator=(QueueStack<T>& other)
	{
		if (this == &other)
		{
			return *this;
		}

		stack<T>* tempStackP;
		while (!mQueueStack.empty())
		{
			tempStackP = mQueueStack.front();
			mQueueStack.pop();

			delete tempStackP;
			tempStackP = nullptr;
		}

		mCount = other.mCount;
		mMaxStackSize = other.mMaxStackSize;
		mSum = other.mSum;

		queue<stack<T>*> tempQueueStack;
		while (!other.mQueueStack.empty())
		{
			stack<T>* tempStackP = other.mQueueStack.front();
			other.mQueueStack.pop();

			tempQueueStack.push(tempStackP);
			mQueueStack.push(new stack<T>(*tempStackP));
		}

		while (!tempQueueStack.empty())
		{
			other.mQueueStack.push(tempQueueStack.front());
			tempQueueStack.pop();
		}

		return *this;
	}

	template<typename T>
	void QueueStack<T>::Enqueue(T number)
	{
		queue<stack<T>*> tempQueueStack;
		stack<T>* tempStackP = nullptr;

		bool bPushed = false;
		while (!mQueueStack.empty())
		{
			tempStackP = mQueueStack.front();
			mQueueStack.pop();
			if (tempStackP->size() < mMaxStackSize)
			{
				tempStackP->push(number);
				++mCount;

				bPushed = true;
			}

			tempQueueStack.push(tempStackP);
		}

		while (!tempQueueStack.empty())
		{
			mQueueStack.push(tempQueueStack.front());
			tempQueueStack.pop();
		}

		if (!bPushed)
		{
			tempStackP = new stack<T>;
			tempStackP->push(number);
			mQueueStack.push(tempStackP);

			++mCount;
		}

		mSum += static_cast<double>(number);
	}

	template<typename T>
	T QueueStack<T>::Peek() const
	{
		// ignore empty queue case

		stack<T>* frontStack = mQueueStack.front();

		return frontStack->top();
	}

	template<typename T>
	T QueueStack<T>::Dequeue()
	{
		// ignore empty queue case

		stack<T>* frontStack = mQueueStack.front();
		T value = frontStack->top();
		frontStack->pop();
		--mCount;
		
		if (frontStack->empty())
		{
			mQueueStack.pop();
			delete frontStack;
			frontStack = nullptr;
		}

		if (mQueueStack.empty())
		{
			mCount = 0;
			mSum = 0.0;

			return value;
		}

		mSum -= static_cast<double>(value);

		return value;
	}

	template<typename T>
	T QueueStack<T>::GetMax()
	{
		T maxValue = numeric_limits<T>::lowest();
		queue<stack<T>*> tempQueueStack;
		stack<T> tempStack;

		while (!mQueueStack.empty())
		{
			stack<T>* tempStackP = mQueueStack.front();
			mQueueStack.pop();
			tempQueueStack.push(tempStackP);

			while (!tempStackP->empty())
			{
				T tempValue = tempStackP->top();
				tempStackP->pop();
				tempStack.push(tempValue);
				if (tempValue > maxValue)
				{
					maxValue = tempValue;
				}
			}

			while (!tempStack.empty())
			{
				tempStackP->push(tempStack.top());
				tempStack.pop();
			}
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
		queue<stack<T>*> tempQueueStack;
		stack<T> tempStack;

		while (!mQueueStack.empty())
		{
			stack<T>* tempStackP = mQueueStack.front();
			mQueueStack.pop();
			tempQueueStack.push(tempStackP);

			while (!tempStackP->empty())
			{
				T tempValue = tempStackP->top();
				tempStackP->pop();
				tempStack.push(tempValue);
				if (tempValue < minValue)
				{
					minValue = tempValue;
				}
			}

			while (!tempStack.empty())
			{
				tempStackP->push(tempStack.top());
				tempStack.pop();
			}
		}

		while (!tempQueueStack.empty())
		{
			mQueueStack.push(tempQueueStack.front());
			tempQueueStack.pop();
		}

		return minValue;
	}

	template<typename T>
	double QueueStack<T>::GetAverage() const
	{
		// ignore empty queue case

		return GetRoundOffTo3DecimalPlaces(mSum / mCount);
	}

	template<typename T>
	T QueueStack<T>::GetSum() const
	{
		if (mSum >= static_cast<double>(numeric_limits<T>::max()))
		{
			return numeric_limits<T>::max();
		}

		return static_cast<T>(mSum);
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