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
		for (size_t i = 0; i < mVehicleCount; ++i)
		{
			mVehicles[i]->AddTravelHour();
		}
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (mVehicleCount >= MAX_VEHICLE_COUNT || vehicle == nullptr)
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

		delete mVehicles[i];
		for (size_t index = i; index < mVehicleCount; ++index)
		{
			mVehicles[index] = mVehicles[index + 1];
		}

		--mVehicleCount;

		return true;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		if (mVehicleCount == 0)
		{
			return nullptr;
		}

		const Vehicle* furtherestTravelledVehicle = mVehicles[0];
		for (size_t i = 1; i < mVehicleCount; ++i)
		{
			if (furtherestTravelledVehicle->GetTotalTravelKilometer() < mVehicles[i]->GetTotalTravelKilometer())
			{
				furtherestTravelledVehicle = mVehicles[i];
			}
		}

		return furtherestTravelledVehicle;
	}
}
