#include "UBoat.h"

namespace assignment2
{
	UBoat::UBoat()
		: Vehicle(50)
	{
		Vehicle::SetDrivePattern(2, 4);
	}

	UBoat::~UBoat()
	{
	}

	unsigned int UBoat::GetMaxSpeed() const
	{
		unsigned int sailSpeed = GetSailSpeed();
		unsigned int diveSpeed = GetDiveSpeed();

		return sailSpeed > diveSpeed ? sailSpeed : diveSpeed;
	}

	unsigned int UBoat::GetSailSpeed() const
	{
		const double MIN_SAIL_SPEED = 200.0;
		int passangerWeight = Vehicle::GetPassangersWeight();
		double result = 550.0 - passangerWeight / 10.0;
		if (result < MIN_SAIL_SPEED)
		{
			result = MIN_SAIL_SPEED;
		}

		return static_cast<unsigned int>(result + 0.5);
	}

	unsigned int UBoat::GetDiveSpeed() const
	{
		int passangerWeight = Vehicle::GetPassangersWeight();
		double result = 500.0 * log((passangerWeight + 150.0) / 150.0) + 30.0;
		
		return static_cast<unsigned int>(result + 0.5);
	}
}
