#pragma once

#include <limits>

using namespace std;

namespace assignment3
{
	template<typename T>
	class SmartQueue
	{
	public:
		SmartQueue();
		virtual ~SmartQueue();

		void Push(T number);
		void Pop();
		T Peek() const;
		T GetMax() const;
		T GetMin() const;
		double GetAverage() const;
		T GetSum() const;
		double GetVariance() const;
		double GetStandardDeviation() const;
		unsigned int GetCount() const;
	private:
		queue<T> mQueue;
	};
}