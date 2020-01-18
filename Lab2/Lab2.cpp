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

			if (!in.fail())
			{
				if (number < 0)
				{
					continue;
				}

				out << setfill(' ') << setw(OUT_LENGTH) << right << noshowbase << oct << number;
				out << setw(OUT_LENGTH - 1) << showbase << dec << number;
				out << setw(OUT_LENGTH - 3) << uppercase << noshowbase << hex << number << endl;

				continue;
			}

			if (in.eof())
			{
				break;
			}

			in.clear();
			in >> trash;
		}
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		constexpr int OUT_LENGTH = 14;
		constexpr int FLOAT_PRECISION = 3;
		float maxFloat = NULL;
		char pos;

		while (true)
		{
			float number;
			string trash;

			in >> number;

			if (!in.fail())
			{
				float outNumber = number;

				if (number >= 0)
				{
					pos = '+';
				}
				else
				{
					pos = '-';
					outNumber = -number;
				}

				out << setfill(' ') << setw(6) << right << pos;
				out << setw(OUT_LENGTH) << fixed << showbase << setprecision(FLOAT_PRECISION) << outNumber << endl;
				
				if (maxFloat == NULL || number > maxFloat)
				{
					maxFloat = number;
				}

				continue;
			}

			if (in.eof())
			{
				break;
			}

			in.clear();
			in >> trash;
		}

		if (maxFloat >= 0)
		{
			pos = '+';
		}
		else
		{
			pos = '-';
			maxFloat = -maxFloat;
		}

		out << "max: " << pos << setfill(' ') << setw(OUT_LENGTH) << right << fixed << showbase << setprecision(FLOAT_PRECISION) << maxFloat << endl;
	}
}
