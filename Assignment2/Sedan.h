#pragma once

#include "Vehicle.h"
#include "Trailer.h"
#include "IDrivable.h"

namespace assignment2
{
	class Trailer;

	class Sedan : public Vehicle, public IDrivable
	{
	public:
		Sedan();
		virtual ~Sedan();
		Sedan(const Sedan& other);

		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();

		unsigned int GetMaxSpeed() const;
		unsigned int GetDriveSpeed() const;
	private:
		const Trailer* mTrailer;
	};
}
