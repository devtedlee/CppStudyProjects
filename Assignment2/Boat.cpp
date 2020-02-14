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
		size_t i = 0;
		size_t passCount = GetPassengersCount();
		for (; i < passCount; ++i)
		{
			bp->AddPassenger(GetPassenger(0));
			MovePassenger(0);
		}

		passCount = plane.GetPassengersCount();
		for (i = 0; i < passCount; ++i)
		{
			bp->AddPassenger(plane.GetPassenger(0));
			plane.MovePassenger(0);
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
