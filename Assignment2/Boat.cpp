#include "Airplane.h"
#include "Boat.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boat::~Boat()
	{
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		Boatplane* bp = new Boatplane(GetMaxPassengersCount() + plane.GetMaxPassengersCount());

		const Person* passanger = GetPassenger(0);
		while (passanger != NULL)
		{
			bp->AddPassenger(GetPassenger(0));
			RemovePassenger(0);
		}

		passanger = plane.GetPassenger(0);
		while (passanger != NULL)
		{
			bp->AddPassenger(plane.GetPassenger(0));
			plane.RemovePassenger(0);
		}

		return *bp;
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
