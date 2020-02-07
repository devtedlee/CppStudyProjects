#include "Lawn.h"

namespace lab5
{
	Lawn::Lawn()
	{
	}

	Lawn::~Lawn()
	{
	}

	unsigned int Lawn::GetGrassPrice(eGrassType grassType) const
	{
		unsigned int area = GetArea();

		unsigned int grassPriceCent = area * static_cast<unsigned int>(grassType);

		double grassPriceDollor = static_cast<double>(grassPriceCent) / 100;

		unsigned int price = static_cast<unsigned int>(grassPriceDollor);
		if (grassPriceDollor == static_cast<double>(price))
		{
			return price;
		}

		return price + 1;
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		unsigned int area = GetArea();

		double rollCountDouble = static_cast<double>(area) / 0.3;

		unsigned int rollCount = static_cast<unsigned int>(rollCountDouble);
		if (rollCountDouble == static_cast<double>(rollCount))
		{
			return rollCount;
		}

		return rollCount + 1;
	}
}
