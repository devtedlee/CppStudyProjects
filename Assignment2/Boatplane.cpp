#define M_E (2.71828182845904523536)
#include <cmath>
#include "Boatplane.h"
#include "Boat.h"
#include "Airplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
		Vehicle::SetDrivePattern(1, 3);
	}

	Boatplane::Boatplane(Airplane& plane, Boat& boat)
		: Vehicle(plane.GetMaxPassengersCount() + boat.GetMaxPassengersCount())
	{
		size_t i = 0;
		size_t passCount = plane.GetPassengersCount();
		for (; i < passCount; ++i)
		{
			AddPassenger(new Person(*(plane.GetPassenger(0))));
			plane.RemovePassenger(0);
		}

		passCount = boat.GetPassengersCount();
		for (i = 0; i < passCount; ++i)
		{
			AddPassenger(new Person(*(boat.GetPassenger(0))));
			boat.RemovePassenger(0);
		}
	}

	Boatplane::~Boatplane()
	{
	}

	Boatplane::Boatplane(const Boatplane& other)
		: Vehicle(other)
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
