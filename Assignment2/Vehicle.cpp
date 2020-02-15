#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mPassengersCount(0)
		, mMaxPassengersCount(maxPassengersCount)
		, mRunnableHours(0)
		, mBreakHours(0)
		, mTotalTravelHours(0)
	{
		mPassangers = new const Person*[mMaxPassengersCount];
	}

	Vehicle::~Vehicle()
	{
		for (size_t i = 0; i < mPassengersCount; ++i)
		{
			delete mPassangers[i];
			mPassangers[i] = nullptr;
		}

		delete[] mPassangers;
		mPassangers = nullptr;
	}

	Vehicle::Vehicle(const Vehicle& other)
		: mMaxPassengersCount(other.mMaxPassengersCount)
		, mRunnableHours(other.mRunnableHours)
		, mBreakHours(other.mBreakHours)
		, mTotalTravelHours(other.mTotalTravelHours)
	{
		size_t i = 0;
		for (; i < mPassengersCount; ++i)
		{
			delete mPassangers[i];
			mPassangers[i] = nullptr;
		}

		delete[] mPassangers;
		mPassangers = nullptr;

		mPassengersCount = other.mPassengersCount;
		mPassangers = new const Person*[mPassengersCount];
		for (i = 0; i < mPassengersCount; ++i)
		{
			mPassangers[i] = new Person(*(other.mPassangers[i]));
		}
	}

	Vehicle& Vehicle::operator=(const Vehicle& other)
	{
		if (this == &other)
		{
			return *this;
		}

		mMaxPassengersCount = other.mMaxPassengersCount;
		mRunnableHours = other.mRunnableHours;
		mBreakHours = other.mBreakHours;
		mTotalTravelHours = other.mTotalTravelHours;
		
		size_t i = 0;
		for (; i < mPassengersCount; ++i)
		{
			delete mPassangers[i];
			mPassangers[i] = nullptr;
		}
		delete[] mPassangers;
		mPassangers = nullptr;

		mPassengersCount = other.mPassengersCount;
		mPassangers = new const Person*[mPassengersCount];
		for (i = 0; i < mPassengersCount; ++i)
		{
			mPassangers[i] = new Person(*(other.mPassangers[i]));
		}

		return *this;
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (mMaxPassengersCount <= mPassengersCount || person == nullptr)
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

		delete mPassangers[i];
		for (size_t index = i; index < mPassengersCount; ++index)
		{
			mPassangers[index] = mPassangers[index + 1];
		}
		--mPassengersCount;

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

	void Vehicle::SetDrivePattern(unsigned int runnableHours, unsigned int breakHours)
	{
		mRunnableHours = runnableHours;
		mBreakHours = breakHours;
	}

	void Vehicle::ResetTotalDriveHours()
	{
		mTotalTravelHours = 0;
	}

	void Vehicle::AddTravelHour()
	{
		++mTotalTravelHours;
	}

	unsigned int Vehicle::GetTotalTravelKilometer() const
	{
		unsigned int result = 0;
		unsigned int maxSpeed = GetMaxSpeed();
		unsigned int totalHours = mTotalTravelHours;
		unsigned int runnalbleHours = mRunnableHours;
		unsigned int breakHours = mBreakHours;

		while (totalHours != 0)
		{
			while (runnalbleHours != 0 && totalHours != 0)
			{
				result += maxSpeed;

				--runnalbleHours;
				--totalHours;
			}

			while (breakHours != 0 && totalHours != 0)
			{
				--breakHours;
				--totalHours;
			}
			runnalbleHours = mRunnableHours;
			breakHours = mBreakHours;
		}

		return result;
	}

	bool Vehicle::MovePassenger(unsigned int i)
	{
		if (mPassengersCount == 0 || mPassengersCount <= i)
		{
			return false;
		}

		for (size_t index = i; index < mPassengersCount; ++index)
		{
			mPassangers[index] = mPassangers[index + 1];
		}
		--mPassengersCount;

		return true;
	}
}
