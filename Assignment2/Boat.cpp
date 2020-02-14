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
		Boatplane* bp = new Boatplane(GetMaxPassengersCount() + plane.GetMaxPassengersCount());
		
		size_t i = 0;
		size_t passCount = GetPassengersCount();

		passCount = plane.GetPassengersCount();
		for (; i < passCount; ++i)
		{
			bp->AddPassenger(new Person(*(plane.GetPassenger(0))));
			plane.RemovePassenger(0);
		}

		passCount = GetPassengersCount();
		for (i = 0; i < passCount; ++i)
		{
			bp->AddPassenger(new Person(*GetPassenger(0)));
			RemovePassenger(0);
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
