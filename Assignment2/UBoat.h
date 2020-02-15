#pragma once

#include "Vehicle.h"
#include "ISailable.h"
#include "IDivable.h"

namespace assignment2
{
	class UBoat : public Vehicle, public ISailable, public IDivable
	{
	public:
		UBoat();
		virtual ~UBoat();
		UBoat(const UBoat& other);
		UBoat& operator=(const UBoat& other);

		unsigned int GetMaxSpeed() const;
		unsigned int GetSailSpeed() const;
		unsigned int GetDiveSpeed() const;
	};
}
