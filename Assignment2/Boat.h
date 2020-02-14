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
		Boat(const Boat& other);

		Boatplane operator+(Airplane& plane);

		unsigned int GetMaxSpeed() const;
		unsigned int GetSailSpeed() const;
	};
}
