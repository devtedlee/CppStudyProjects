#include <cmath>
#include "TimeSheet.h"

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
		: mName(name)
		, mMaxEntryCount(maxEntries)
		, mCurrentEntryCount(0)
	{
		mWorkHours = new int[maxEntries];
	}

	TimeSheet::TimeSheet(const TimeSheet& origin)
		: mName(origin.mName)
		, mMaxEntryCount(origin.mMaxEntryCount)
		, mCurrentEntryCount(origin.mCurrentEntryCount)
	{
		mWorkHours = new int[mMaxEntryCount];
		
		int* workHours = mWorkHours;
		for (size_t i = 0; i < mCurrentEntryCount; ++i)
		{
			*workHours = origin.mWorkHours[i];
			++workHours;
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

		if (timeInHours < MIN_HOUR || timeInHours > MAX_HOUR)
		{
			return;
		}

		if (mCurrentEntryCount == mMaxEntryCount)
		{
			return;
		}

		mWorkHours[mCurrentEntryCount] = timeInHours;
		++mCurrentEntryCount;
	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		if (index < 0 || index > mCurrentEntryCount - 1)
		{
			return FAILED;
		}

		return mWorkHours[index];
	}

	int TimeSheet::GetTotalTime() const
	{
		int totalTime = 0;

		for (size_t i = 0; i < mCurrentEntryCount; ++i)
		{
			totalTime += mWorkHours[i];
		}

		return totalTime;
	}

	float TimeSheet::GetAverageTime() const
	{
		int totalTime = GetTotalTime();

		if (totalTime == 0)
		{
			return 0.0f;
		}

		return (float)totalTime / mCurrentEntryCount;
	}

	float TimeSheet::GetStandardDeviation() const
	{
		float average = GetAverageTime();
		float result = 0.0f;

		for (size_t i = 0; i < mCurrentEntryCount; ++i)
		{
			float temp_deviation = mWorkHours[i] - average;

			temp_deviation = abs(temp_deviation);

			result += pow(temp_deviation, 2);
		}

		if (result == 0.0f)
		{
			return result;
		}

		result = result / mCurrentEntryCount;

		return sqrt(result);
	}

	const std::string& TimeSheet::GetName() const
	{
		return mName;
	}
}
