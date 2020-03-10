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
		unsigned int GetStackCount() const;
	private:
		unsigned int mCount;
		unsigned int mStackCount;
		unsigned int mMaxStackSize;
		queue<stack<T>*>* mQueueStack;
	};

	template<typename T>
	QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mCount(0)
		, mStackCount(0)
		, mMaxStackSize(maxStackSize)
		, mQueueStack(new queue<stack<T>*>)
	{
	}

	template<typename T>
	QueueStack<T>::~QueueStack()
	{
		stack<T>* tempStackP;
		for (unsigned int i = 0; i < mStackCount; ++i)
		{
			tempStackP = mQueueStack->front();
			mQueueStack->pop();

			delete tempStackP;
		}

		delete mQueueStack;
	}

	template<typename T>
	QueueStack<T>::QueueStack(const QueueStack<T>& other)
		: mCount(other.mCount)
		, mStackCount(other.mStackCount)
		, mMaxStackSize(other.mMaxStackSize)
		, mQueueStack(new queue<stack<T>*>)
	{
		queue<stack<T>*> tempQueueStack;

		for (unsigned int i = 0; i < mStackCount; ++i)
		{
			stack<T>* tempStackP = other.mQueueStack->front();
			other.mQueueStack->pop();

			tempQueueStack->push(tempStackP);
			mQueueStack->push(new stack<T>(*tempStackP));
		}

		for (unsigned int i = 0; i < mStackCount; ++i)
		{
			other.mQueueStack->push(tempQueueStack.front());
			tempQueueStack.pop();
		}
	}

	template<typename T>
	QueueStack<T>& QueueStack<T>::operator=(const QueueStack<T>& other)
	{
		if (this == &other)
		{
			return *this;
		}

		stack<T>* tempStackP;
		for (unsigned int i = 0; i < mStackCount; ++i)
		{
			tempStackP = mQueueStack->front();
			mQueueStack->pop();

			delete tempStackP;
		}

		delete mQueueStack;

		mCount = other.mCount;
		mStackCount = other.mStackCount;
		mMaxStackSize = other.mMaxStackSize;
		mQueueStack = new queue<stack<T>*>;

		queue<stack<T>*> tempQueueStack;

		for (unsigned int i = 0; i < mStackCount; ++i)
		{
			stack<T>* tempStackP = other.mQueueStack->front();
			other.mQueueStack->pop();

			tempQueueStack.push(tempStackP);
			mQueueStack->push(new stack<T>(*tempStackP));
		}

		for (unsigned int i = 0; i < mStackCount; ++i)
		{
			other.mQueueStack->push(tempQueueStack.front());
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
		for (unsigned int i = 0; i < mStackCount; ++i)
		{
			tempStackP = mQueueStack->front();
			mQueueStack->pop();
			if (tempStackP->size() < mMaxStackSize)
			{
				tempStackP->push(number);
				++mCount;

				bPushed = true;
			}

			tempQueueStack.push(tempStackP);
		}

		if (!bPushed)
		{
			tempStackP = new stack<T>;
			tempStackP->push(number);
			tempQueueStack.push(tempStackP);
			++mStackCount;
			++mCount;
		}

		for (unsigned int i = 0; i < mStackCount; ++i)
		{
			mQueueStack->push(tempQueueStack.front());
			tempQueueStack.pop();
		}
	}

	template<typename T>
	T QueueStack<T>::Peek() const
	{
		stack<T>* frontStack = mQueueStack->front();

		return frontStack->top();
	}

	template<typename T>
	T QueueStack<T>::Dequeue()
	{
		stack<T>* frontStack = mQueueStack->front();
		T returnValue = frontStack->top();
		frontStack->pop();
		--mCount;
		
		if (frontStack->empty())
		{
			mQueueStack->pop();
			delete frontStack;
			--mStackCount;
		}

		return returnValue;
	}

	template<typename T>
	T QueueStack<T>::GetMax() const
	{
		T maxValue = numeric_limits<T>::min();
		queue<stack<T>*> tempQueueStack;
		stack<T> tempStack;

		for (unsigned int i = 0; i < mStackCount; ++i)
		{
			stack<T>* tempStackP = mQueueStack->front();
			mQueueStack->pop();
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

		for (unsigned int i = 0; i < mStackCount; ++i)
		{
			mQueueStack->push(tempQueueStack.front());
			tempQueueStack.pop();
		}

		return maxValue;
	}

	template<typename T>
	T QueueStack<T>::GetMin() const
	{
		T minValue = numeric_limits<T>::max();
		queue<stack<T>*> tempQueueStack;
		stack<T> tempStack;

		for (unsigned int i = 0; i < mStackCount; ++i)
		{
			stack<T>* tempStackP = mQueueStack->front();
			mQueueStack->pop();
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

		for (unsigned int i = 0; i < mStackCount; ++i)
		{
			mQueueStack->push(tempQueueStack.front());
			tempQueueStack.pop();
		}

		return minValue;
	}

	template<typename T>
	double QueueStack<T>::GetAverage() const
	{
		T sum = GetSum();

		return GetRoundOffTo3DecimalPlaces(static_cast<double>(sum) / static_cast<double>(mCount));
	}

	template<typename T>
	T QueueStack<T>::GetSum() const
	{
		double sum = 0.0;
		queue<stack<T>*> tempQueueStack;
		stack<T> tempStack;

		for (unsigned int i = 0; i < mStackCount; ++i)
		{
			stack<T>* tempStackP = mQueueStack->front();
			mQueueStack->pop();
			tempQueueStack.push(tempStackP);

			while (!tempStackP->empty())
			{
				T tempValue = tempStackP->top();
				tempStackP->pop();
				tempStack.push(tempValue);
				
				sum += static_cast<double>(tempValue);
			}

			while (!tempStack.empty())
			{
				tempStackP->push(tempStack.top());
				tempStack.pop();
			}
		}

		for (unsigned int i = 0; i < mStackCount; ++i)
		{
			mQueueStack->push(tempQueueStack.front());
			tempQueueStack.pop();
		}

		return static_cast<T>(sum);
	}

	template<typename T>
	double QueueStack<T>::GetVariance() const
	{
		double distanceSum = 0.0;
		double average = GetAverage();

		queue<stack<T>*> tempQueueStack;
		stack<T> tempStack;

		for (unsigned int i = 0; i < mStackCount; ++i)
		{
			stack<T>* tempStackP = mQueueStack->front();
			mQueueStack->pop();
			tempQueueStack.push(tempStackP);

			while (!tempStackP->empty())
			{
				T tempValue = tempStackP->top();
				tempStackP->pop();
				tempStack.push(tempValue);

				distanceSum += pow(abs(static_cast<double>(tempValue) - average), 2.0);
			}

			while (!tempStack.empty())
			{
				tempStackP->push(tempStack.top());
				tempStack.pop();
			}
		}

		for (unsigned int i = 0; i < mStackCount; ++i)
		{
			mQueueStack->push(tempQueueStack.front());
			tempQueueStack.pop();
		}

		return GetRoundOffTo3DecimalPlaces(distanceSum / static_cast<double>(mCount));
	}

	template<typename T>
	double QueueStack<T>::GetStandardDeviation() const
	{
		double variance = GetVariance();

		return GetRoundOffTo3DecimalPlaces(sqrt(variance));
	}

	template<typename T>
	unsigned int QueueStack<T>::GetCount() const
	{
		return mCount;
	}

	template<typename T>
	unsigned int QueueStack<T>::GetStackCount() const
	{
		return mStackCount;
	}
}