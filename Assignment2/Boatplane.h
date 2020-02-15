#pragma once

#include "Vehicle.h"
#include "IFlyable.h"
#include "ISailable.h"

namespace assignment2
{
	class Airplane;
	class Boat;

	class Boatplane : public Vehicle, public IFlyable, public ISailable
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
		Boatplane(Airplane& plane, Boat& boat);
		virtual ~Boatplane();
		Boatplane(const Boatplane& other);
		Boatplane& operator=(const Boatplane& other);

		unsigned int GetMaxSpeed() const;
		unsigned int GetFlySpeed() const;
		unsigned int GetSailSpeed() const;
	};
}
