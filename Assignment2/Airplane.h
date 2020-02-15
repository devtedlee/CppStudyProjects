#pragma once

#include "Vehicle.h"
#include "IFlyable.h"
#include "IDrivable.h"
#include "Boatplane.h"

namespace assignment2
{
	class Boat;

	class Airplane : public Vehicle, public IFlyable, public IDrivable
	{
	public:
		Airplane(unsigned int maxPassengersCount);
		virtual ~Airplane();
		Airplane(const Airplane& other);
		Airplane& operator=(const Airplane& other);

		Boatplane operator+(Boat& boat);
		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetFlySpeed() const;
		virtual unsigned int GetDriveSpeed() const;
	};
}
