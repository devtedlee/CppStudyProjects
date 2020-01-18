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

		out << "		 oct		dec	  hex" << endl;
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
		float max_float = NULL;
		char pos;

		while (true)
		{
			float number;
			string trash;

			in >> number;

			if (!in.fail())
			{
				int out_number = number;

				if (number >= 0)
				{
					pos = '+';
				}
				else
				{
					pos = '-';
					out_number = -number;
				}

				out << setfill(' ') << setw(6) << right << pos;
				out << setw(OUT_LENGTH) << fixed << showbase << setprecision(FLOAT_PRECISION) << out_number << endl;
				
				if (max_float == NULL || number > max_float)
				{
					max_float = number;
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

		if (max_float >= 0)
		{
			pos = '+';
		}
		else
		{
			pos = '-';
			max_float = -max_float;
		}

		out << "max: " << pos << setfill(' ') << setw(OUT_LENGTH) << right << fixed << showbase << setprecision(FLOAT_PRECISION) << max_float << endl;
	}
}
