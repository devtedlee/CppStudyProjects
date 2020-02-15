#include <cmath>
#include "Motorcycle.h"

namespace assignment2
{
	Motorcycle::Motorcycle()
		: Vehicle(2)
	{
		Vehicle::SetDrivePattern(5, 1);
	}

	Motorcycle::~Motorcycle()
	{
	}

	Motorcycle::Motorcycle(const Motorcycle& other)
		: Vehicle(other)
	{
	}

	Motorcycle& Motorcycle::operator=(const Motorcycle& other)
	{
		if (this == &other)
		{
			return *this;
		}

		Vehicle::operator=(other);

		return *this;
	}

	unsigned int Motorcycle::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	unsigned int Motorcycle::GetDriveSpeed() const
	{
		int passangersWeight = Vehicle::GetPassangersWeight();
		double result = pow(-(passangersWeight / 15), 3.0) + 2.0 * passangersWeight + 400.0;

		if (result < 0.0)
		{
			return 0;
		}

		return static_cast<unsigned int>(result + 0.5);
	}
}
