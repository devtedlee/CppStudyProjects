#pragma once

#include <limits>
#include <queue>
#include <stack>

using namespace std;

namespace assignment3
{
	template<typename T>
	class QueueStack
	{
	public:
		QueueStack(unsigned int maxStackSize);
		virtual ~QueueStack();

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
		stack<T>* tempStack;
		for (unsigned int i = 0; i < mStackCount; ++i)
		{
			tempStack = mQueueStack->front();
			mQueueStack->pop();

			delete tempStack;
		}

		delete mQueueStack;
	}

	template<typename T>
	void QueueStack<T>::Enqueue(T number)
	{
	}

	template<typename T>
	T QueueStack<T>::Peek() const
	{
		T a = 0;

		return a;
	}

	template<typename T>
	T QueueStack<T>::Dequeue()
	{
		T a = 0;

		return a;
	}

	template<typename T>
	T QueueStack<T>::GetMax() const
	{
		T a = 0;

		return a;
	}

	template<typename T>
	T QueueStack<T>::GetMin() const
	{
		T a = 0;

		return a;
	}

	template<typename T>
	double QueueStack<T>::GetAverage() const
	{
		return 0.0;
	}

	template<typename T>
	T QueueStack<T>::GetSum() const
	{
		T a = 0;

		return a;
	}

	template<typename T>
	double QueueStack<T>::GetVariance() const
	{
		return 0.0;
	}

	template<typename T>
	double QueueStack<T>::GetStandardDeviation() const
	{
		return 0.0;
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