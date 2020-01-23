#include <string>
#include <iostream>
#include <iomanip>
#include "Lab2.h"

using namespace std;

namespace lab2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		constexpr int OUT_LENGTH = 12;

		out << "         oct        dec      hex" << endl;
		out << "------------ ---------- --------" << endl;

		while (true) 
		{
			int number;
			string trash;

			in >> number;

			if (in.fail())
			{
				if (in.eof())
				{
					break;
				}

				in.clear();
				in >> trash;
			}

			if (number < 0)
			{
				continue;
			}

			out << setfill(' ') << setw(OUT_LENGTH) << right << noshowbase << oct << number
				<< setw(OUT_LENGTH - 1) << showbase << dec << number
				<< setw(OUT_LENGTH - 3) << uppercase << noshowbase << hex << number << endl;
		}
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		constexpr int OUT_LENGTH = 15;
		constexpr int FLOAT_PRECISION = 3;
		float maxFloat = -FLT_MAX;

		while (true)
		{
			float number;
			string trash;

			in >> number;

			if (in.fail())
			{
				if (in.eof())
				{
					break;
				}

				in.clear();
				in >> trash;

				continue;
			}

			if (number > maxFloat)
			{
				maxFloat = number;
			}

			out << setfill(' ') << setw(5) << ' ' << setw(OUT_LENGTH) << showpos << internal << fixed << showbase << setprecision(FLOAT_PRECISION) << number << endl;
		}

		out << "max: " << setw(OUT_LENGTH) << maxFloat << endl;
	}
}
