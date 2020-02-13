#include "DeusExMachina.h"

namespace assignment2
{
	DeusExMachina* DeusExMachina::GetInstance()
	{
		static DeusExMachina* instance;
		if (instance == nullptr)
		{
			instance = new DeusExMachina();
		}
		
		return instance;
	}

	void DeusExMachina::Travel() const
	{
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (mVehicleCount >= MAX_VEHICLE_COUNT)
		{
			return false;
		}

		mVehicles[mVehicleCount] = vehicle;
		++mVehicleCount;

		return true;
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (mVehicleCount == 0 || mVehicleCount <= i)
		{
			return false;
		}

		--mVehicleCount;

		for (size_t index = i; index < mVehicleCount; ++index)
		{
			mVehicles[i] = mVehicles[i + 1];
		}

		return true;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		return NULL;
	}
}
