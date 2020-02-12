#pragma once

#include "Vehicle.h"
#include "ISailable.h"
#include "Boatplane.h"

namespace assignment2
{
	class Airplane;

	class Boat : public Vehicle, public ISailable
	{
	public:
		Boat(unsigned int maxPassengersCount);
		virtual ~Boat();

		Boatplane operator+(Airplane& plane);

		unsigned int GetMaxSpeed() const;
		unsigned int GetSailSpeed() const;
	};
}
