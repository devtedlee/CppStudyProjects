#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mPassengersCount(0)
		, mMaxPassengersCount(maxPassengersCount)
	{
		mPassangers = new const Person*[mMaxPassengersCount];
	}

	Vehicle::~Vehicle()
	{
		delete[] mPassangers;
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (mMaxPassengersCount <= mPassengersCount)
		{
			return false;
		}

		mPassangers[mPassengersCount] = person;

		++mPassengersCount;

		return true;
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (mPassengersCount == 0 || mPassengersCount <= i)
		{
			return false;
		}

		--mPassengersCount;

		for (size_t index = i; index < mPassengersCount; ++index)
		{
			mPassangers[i] = mPassangers[i + 1];
		}

		return true;
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return mPassengersCount;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxPassengersCount;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (mPassengersCount == 0 || mPassengersCount <= i)
		{
			return NULL;
		}

		return mPassangers[i];
	}

	int Vehicle::GetPassangersWeight() const
	{
		unsigned int weightSum = 0;

		for (size_t i = 0; i < mPassengersCount; ++i)
		{
			weightSum += mPassangers[i]->GetWeight();
		}

		return static_cast<int>(weightSum);
	}
}
