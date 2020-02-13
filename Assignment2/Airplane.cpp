#define _USE_MATH_DEFINES
#include <cmath>
#include "Airplane.h"
#include "Boat.h"

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Airplane::~Airplane()
	{
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		Boatplane* bp = new Boatplane(GetMaxPassengersCount() + boat.GetMaxPassengersCount());
		
		const Person* passanger = GetPassenger(0);
		while (passanger != NULL)
		{
			bp->AddPassenger(passanger);
			RemovePassenger(0);

			passanger = GetPassenger(0);
		}

		passanger = boat.GetPassenger(0);
		while (passanger != NULL)
		{
			bp->AddPassenger(passanger);
			boat.RemovePassenger(0);

			passanger = boat.GetPassenger(0);
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
