#include <string>
#include <iostream>
#include <iomanip>
#include "Lab2.h"

using namespace std;

namespace lab2
{
    void PrintIntegers(std::istream& in, std::ostream& out)
    {
        const int OUT_LENGTH = 12;
        int number;
        string trash;

        out << "         oct        dec      hex" << endl;
        out << "------------ ---------- --------" << endl;

        while (true) 
        {
            in >> number;

            if (!in.fail())
            {
                out << setfill(' ') << setw(OUT_LENGTH) << right << showbase << oct << number;
                out << setfill(' ') << setw(OUT_LENGTH) << right << showbase << dec << number;
                out << setfill(' ') << setw(OUT_LENGTH) << right << uppercase << noshowbase << hex << number << endl;

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
        const int OUT_LENGTH = 14;
        const int FLOAT_PRECISION = 3;
        float number;
        float max_float = NULL;
        string trash;
        char pos;

        while (true)
        {
            in >> number;

            if (!in.fail())
            {
                pos = number >= 0 ? '+' : '-';

                out << setfill(' ') << setw(6) << right << pos;
                out << setfill(' ') << setw(OUT_LENGTH) << right << showbase << setprecision(FLOAT_PRECISION) << number;
                
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

        pos = max_float >= 0 ? '+' : '-';
        out << "max: " << pos << setfill(' ') << setw(OUT_LENGTH) << right << showbase << setprecision(FLOAT_PRECISION) << max_float << endl;
    }
}
