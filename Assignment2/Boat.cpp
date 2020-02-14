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

	Boatplane Boat::operator+(Airplane& plane)
	{
		Boatplane* bp = new Boatplane(GetMaxPassengersCount() + plane.GetMaxPassengersCount());
		const Person* passenger;

		int passIndex = static_cast<int>(GetPassengersCount()) - 1;
		for (; passIndex > -1; --passIndex)
		{
			passenger = GetPassenger(passIndex);
			bp->AddPassenger(new Person(*passenger));
			MovePassenger(passIndex);
		}

		passIndex = static_cast<int>(plane.GetPassengersCount()) - 1;
		for (; passIndex > -1; --passIndex)
		{
			passenger = plane.GetPassenger(passIndex);
			bp->AddPassenger(new Person(*passenger));
			plane.MovePassenger(passIndex);
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
