#include <iostream>
#include <bitset>
#include <iomanip>
#include "Add.h"

using namespace lab1;
using namespace std;

class Lae
{
public:
	int mData[2];
	Lae(int x, int y) { mData[0] = x; mData[1] = y; }
	virtual void f() {}
};

void swap(int& x, int& y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

int main()
{
	int result = Add(1, 2);

	cout << "Hello, " << "WORLD :" << result << endl;

	// Output excercise

	/*
	int num = 10;
	cout << showbase << hex << num << endl;

	const float number = 123.456789f;
	cout << setprecision(7) << scientific << number << endl;
	cout << setprecision(8) << fixed << number << endl;
	*/

	cout << setw(15) << setfill('-') << internal << "Hello Wrold" << endl;

	float* x = new float(12.456f);
	int* y = reinterpret_cast<int*>(x);
	float* z = reinterpret_cast<float*>(y);

	cout << *z << endl;

	int a = 14;
	int b = 3;
	swap(a, b);
	cout << a << endl;

	Lae ar(10, 20);
	int* arr = (int*)&ar;
	cout << arr[2] << endl;

	int sd = 1;
	float dd = 1;

	cout << bitset<99>(dd) << endl;

	return result;
}