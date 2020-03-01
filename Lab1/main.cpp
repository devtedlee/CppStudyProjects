#include <iostream>
#include <iomanip>
#include "Add.h"

using namespace lab1;
using namespace std;

int main()
{
	int result = Add(1, 2);

	cout << "Hello, " << "WORLD :" << result << endl;

	// Output excercise

	int num = 10;
	cout << showbase << hex << num << endl;

	const float number = 123.456789f;
	cout << setprecision(7) << scientific << number << endl;
	cout << setprecision(8) << fixed << number << endl;

	return result;
}