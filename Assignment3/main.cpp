#include <cassert>

#include "SmartStack.h"
#include "SmartQueue.h"
#include "QueueStack.h"

using namespace assignment3;

int main()
{
	SmartStack<char> cs;
	cs.Push('a');
	cs.Push('b');
	cs.Push('c');
	cs.Push('d');
	cs.Push('1');
	cs.Push('5');
	cs.Push(' ');
	cs.Push('A');
	cs.Push('2');
	cs.Push('-');

	cs.GetCount();
	cs.Peek();
	cs.GetMax();
	cs.GetMin();
	cs.GetSum();
	cs.GetAverage();
	cs.GetVariance();
	cs.GetStandardDeviation();
	cs.Peek();

	SmartStack<int> s;
	s.Push(6);
	s.Push(5);
	s.Push(-2); // [ 6, 5, -2 ]
	double variance = s.GetVariance(); // 12.667
	double standardDeviation = s.GetStandardDeviation(); // 3.559
	double average = s.GetAverage(); // 3.000

	SmartStack<double> ds;

	ds.Push(3.4);
	ds.Push(1.2);
	ds.Push(4.6);
	ds.Push(3.32);
	ds.Push(10.2);
	ds.Push(1.1);
	ds.Push(-5.9);
	ds.Push(1.1);
	ds.Push(-12.4);
	ds.Push(9.2);

	assert(ds.GetCount() == 10U);
	assert(ds.Peek() == 9.2);
	assert(ds.GetMax() == 10.2);
	assert(ds.GetMin() == -12.4);
	//assert(ds.GetSum() == 15.82);
	assert(ds.GetAverage() == 1.582);
	assert(ds.GetVariance() == 39.983);
	assert(ds.GetStandardDeviation() == 6.323);
	assert(ds.Peek() == 9.2);

	double dpopped1 = ds.Pop();
	double dpopped2 = ds.Pop();

	assert(dpopped1 == 9.2);
	assert(dpopped2 == -12.4);


	SmartStack<float> ss;

	ss.Push(3.4999f);
	ss.Push(1.2f);
	ss.Push(4.6555f);
	ss.Push(3.3299f);
	ss.Push(10.2f);
	ss.Push(1.1f);
	ss.Push(-5.9f);
	ss.Push(1.1f);
	ss.Push(-12.4f);
	ss.Push(9.2f);

	assert(ss.Peek() == 9.2f);
	assert(ss.GetMax() == 10.2f);
	assert(ss.GetMin() == -12.4f);
	assert(ss.GetCount() == 10U);
	//assert(ss.GetSum() == 15.985301f);
	assert(ss.GetAverage() == 1.599);
	assert(ss.GetVariance() == 40.057);
	assert(ss.GetStandardDeviation() == 6.329);
	assert(ss.Peek() == 9.2f);

	float popped1 = ss.Pop();
	float popped2 = ss.Pop();

	assert(popped1 == 9.2f);
	assert(popped2 == -12.4f);
	assert(ss.GetCount() == 8U);
	assert(ss.Peek() == 1.1f);
	assert(ss.GetMax() == 10.2f);
	assert(ss.GetMin() == -5.9f);
	//assert(ss.GetSum() == 19.1853008f);
	assert(ss.GetAverage() == 2.398);
	assert(ss.GetVariance() == 17.714);
	assert(ss.GetStandardDeviation() == 4.209);

	SmartStack<int> ss_copy1(s);

	SmartStack<float> ss_copy2 = ss;

	SmartQueue<float> sq;

	sq.Enqueue(3.4999f);
	sq.Enqueue(1.2f);
	sq.Enqueue(4.6555f);
	sq.Enqueue(3.3299f);
	sq.Enqueue(10.2f);
	sq.Enqueue(1.1f);
	sq.Enqueue(-5.9f);
	sq.Enqueue(1.1f);
	sq.Enqueue(-12.4f);
	sq.Enqueue(9.2f);

	assert(sq.GetCount() == 10U);
	assert(sq.Peek() == 3.4999f);
	assert(sq.GetMax() == 10.2f);
	assert(sq.GetMin() == -12.4f);
	//assert(sq.GetSum() == 15.9853010f);
	assert(sq.GetAverage() == 1.599);
	assert(sq.GetVariance() == 40.057);
	assert(sq.GetStandardDeviation() == 6.329);
	assert(sq.Peek() == 3.4999f);

	float dequeued1 = sq.Dequeue();
	float dequeued2 = sq.Dequeue();

	assert(dequeued1 == 3.4999f);
	assert(dequeued2 == 1.2f);
	assert(sq.GetCount() == 8U);
	assert(sq.Peek() == 4.6555f);
	assert(sq.GetMax() == 10.2f);
	assert(sq.GetMin() == -12.4f);
	//assert(sq.GetSum() == 11.2854013f);
	assert(sq.GetAverage() == 1.411);
	assert(sq.GetVariance() == 49.564);
	assert(sq.GetStandardDeviation() == 7.040);

	QueueStack<float> qs(3);

	qs.Enqueue(3.4f);
	qs.Enqueue(1.2f);
	qs.Enqueue(4.6f);
	qs.Enqueue(3.32f);
	qs.Enqueue(10.2f);
	qs.Enqueue(1.1f);
	qs.Enqueue(-5.9f);
	qs.Enqueue(1.1f);
	qs.Enqueue(-12.4f);
	qs.Enqueue(9.2f);

	assert(qs.GetStackCount() == 4U);
	assert(qs.Peek() == 4.6f);
	assert(qs.GetCount() == 10U);
	assert(qs.GetMax() == 10.2f);
	assert(qs.GetMin() == -12.4f);
	//assert(qs.GetSum() == 15.8200026f);
	assert(qs.GetAverage() == 1.582);
	assert(qs.GetStackCount() == 4U);
	assert(qs.Peek() == 4.6f);

	float dequeued3 = qs.Dequeue();
	float dequeued4 = qs.Dequeue();
	float dequeued5 = qs.Dequeue();

	assert(dequeued3 == 4.6f);
	assert(dequeued4 == 1.2f);
	assert(dequeued5 == 3.4f);
	assert(qs.Peek() == 1.1f);
	assert(qs.GetCount() == 7U);
	assert(qs.GetStackCount() == 3U);
	assert(qs.GetMax() == 10.2f);
	assert(qs.GetMin() == -12.4f);
	//assert(qs.GetSum() == 6.62000322f);
	assert(qs.GetAverage() == 0.946);

	return 0;
}
