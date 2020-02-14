#define M_E (2.71828182845904523536)
#include <cmath>
#include "Airplane.h"
#include "Boat.h"

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
		Vehicle::SetDrivePattern(1, 3);
	}

	Airplane::~Airplane()
	{
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		Boatplane* bp = new Boatplane(GetMaxPassengersCount() + boat.GetMaxPassengersCount());

		size_t i = 0;
		size_t passCount = GetPassengersCount();
		for (; i < passCount; ++i)
		{
			bp->AddPassenger(GetPassenger(0));
			MovePassenger(0);
		}

		passCount = boat.GetPassengersCount();
		for (i = 0; i < passCount; ++i)
		{
			bp->AddPassenger(boat.GetPassenger(0));
			boat.MovePassenger(0);
		}

		return *bp;
	}

	unsigned int Airplane::GetMaxSpeed() const
	{
		unsigned int flySpeed = GetFlySpeed();
		unsigned int driveSpeed = GetDriveSpeed();

		return flySpeed > driveSpeed ? flySpeed : driveSpeed;
	}

	unsigned int Airplane::GetFlySpeed() const
	{
		int passangersWeight = Vehicle::GetPassangersWeight();
		double result = 200.0 * pow(M_E, ((-passangersWeight + 800.0) / 500.0));
		return static_cast<unsigned int>(result + 0.5);
	}

	unsigned int Airplane::GetDriveSpeed() const
	{
		int passangersWeight = Vehicle::GetPassangersWeight();
		double result = 4.0 * pow(M_E, ((-passangersWeight + 400.0) / 70.0));
		return static_cast<unsigned int>(result + 0.5);
	}
}
