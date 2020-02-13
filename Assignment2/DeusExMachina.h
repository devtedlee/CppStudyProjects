#pragma once

#include "Vehicle.h"

namespace assignment2
{
	class DeusExMachina
	{
	public:
		static DeusExMachina* GetInstance();
		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		bool RemoveVehicle(unsigned int i);
		const Vehicle* GetFurthestTravelled() const;
	private:
		enum
		{
			MAX_VEHICLE_COUNT = 10
		};
		Vehicle* mVehicles[MAX_VEHICLE_COUNT];
		unsigned int mVehicleTravelDistances[MAX_VEHICLE_COUNT];
		size_t mVehicleCount;
		DeusExMachina()
			: mVehicleCount(0)
			, mVehicleTravelDistances()
			, mVehicles()
		{
		};
	};
}
