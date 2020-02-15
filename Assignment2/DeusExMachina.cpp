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

	DeusExMachina::~DeusExMachina()
	{
		for (size_t i = 0; i < mVehicleCount; ++i)
		{
			delete mVehicles[i];
		}
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
		const Vehicle* furtherestTravelledVehicle = nullptr;

		unsigned int furtherestKillometer = 0;
		for (size_t i = 0; i < mVehicleCount; ++i)
		{
			unsigned int tempTravelKilometer = mVehicles[i]->GetTotalTravelKilometer();
			if (furtherestKillometer < tempTravelKilometer)
			{
				furtherestKillometer = tempTravelKilometer;
				furtherestTravelledVehicle = mVehicles[i];
			}
		}

		return furtherestTravelledVehicle;
	}
}
