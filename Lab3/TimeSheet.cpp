#include "TimeSheet.h"

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
	{
		mName = name;
		mWorkHours = new int[maxEntries];
		mMaxEntryCount = maxEntries;
	}

	TimeSheet::TimeSheet(const TimeSheet& origin)
	{
		int* originWorkHourP = origin.mWorkHours;

		mName = origin.mName;
		mMaxEntryCount = origin.mMaxEntryCount;
		mWorkHours = new int[mMaxEntryCount];

		int* workHoursP = mWorkHours;
		while (++*originWorkHourP != NULL)
		{
			*workHoursP = *originWorkHourP;
			++workHoursP;
		}
	}

	TimeSheet::~TimeSheet(void)
	{
		delete[] mWorkHours;
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		const int MIN_HOUR = 1;
		const int MAX_HOUR = 10;
		int* workHourP = &mWorkHours[0];
		int workHourSum = 0;

		if (timeInHours < MIN_HOUR || timeInHours > MAX_HOUR)
		{
			return;
		}

		while (++*workHourP != NULL)
		{
			workHourSum += *workHourP;
		}

		workHourSum += timeInHours;
		if (workHourSum < MIN_HOUR || workHourSum > MAX_HOUR)
		{
			return;
		}

		*workHourP = timeInHours;
	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		return 0;
	}

	int TimeSheet::GetTotalTime() const
	{
		return 0;
	}

	float TimeSheet::GetAverageTime() const
	{
		return 0.0f;
	}

	float TimeSheet::GetStandardDeviation() const
	{
		return 0.0f;
	}

	const std::string& TimeSheet::GetName() const
	{
		return mName;
	}
}
