#define _USE_MATH_DEFINES
#include <cmath>
#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
		Vehicle::SetDrivePattern(1, 3);
	}

	Boatplane::~Boatplane()
	{
	}

	unsigned int Boatplane::GetMaxSpeed() const
	{
		unsigned int flySpeed = GetFlySpeed();
		unsigned int driveSpeed = GetSailSpeed();

		return flySpeed > driveSpeed ? flySpeed : driveSpeed;
	}

	unsigned int Boatplane::GetFlySpeed() const
	{
		int passangersWeight = Vehicle::GetPassangersWeight();
		double result = 150.0 * pow(M_E, ((-passangersWeight + 500.0) / 300.0));
		return static_cast<unsigned int>(result + 0.5);
	}

	unsigned int Boatplane::GetSailSpeed() const
	{
		const int MIN_SAIL_SPEED = 20;
		int passangersWeight = Vehicle::GetPassangersWeight();
		int result = static_cast<int>((800 - 1.7 * passangersWeight) + 0.5);

		if (result < MIN_SAIL_SPEED)
		{
			result = MIN_SAIL_SPEED;
		}

		return static_cast<unsigned int>(result);
	}
}
