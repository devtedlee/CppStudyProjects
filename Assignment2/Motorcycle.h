#pragma once

#include "Vehicle.h"
#include "IDrivable.h"

namespace assignment2
{
	class Motorcycle : public Vehicle, public IDrivable
	{
	public:
		Motorcycle();
		virtual ~Motorcycle();
		Motorcycle(const Motorcycle& other);
		Motorcycle& operator=(const Motorcycle& other);

		unsigned int GetMaxSpeed() const;
		unsigned int GetDriveSpeed() const;
	};
}
