#include "MyMath.h"

namespace assignment3
{
	double GetRoundOffTo3DecimalPlaces(const double number)
	{
		return round(number * 1000) / 1000;
	}
}