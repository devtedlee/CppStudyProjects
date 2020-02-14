#include "Airplane.h"
#include "Boat.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
		Vehicle::SetDrivePattern(2, 1);
	}

	Boat::~Boat()
	{
	}

	Boat::Boat(const Boat& other)
		: Vehicle(other)
	{
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		return Boatplane(plane, *this);
	}

	unsigned int Boat::GetMaxSpeed() const
	{
		return GetSailSpeed();
	}

	unsigned int Boat::GetSailSpeed() const
	{
		const int MIN_SAIL_SPEED = 20;
		int passangersWeight = Vehicle::GetPassangersWeight();
		int result = 800 - 10 * passangersWeight;

		if (result < MIN_SAIL_SPEED)
		{
			result = MIN_SAIL_SPEED;
		}

		return static_cast<unsigned int>(result);
	}
}
