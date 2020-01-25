#pragma once
#include <string>

namespace lab3
{
	class TimeSheet
	{
	public:
		TimeSheet(const char* name, unsigned int maxEntries);
		TimeSheet(const TimeSheet& origin);
		~TimeSheet(void);
		void AddTime(int timeInHours);
		int GetTimeEntry(unsigned int index) const;
		int GetTotalTime() const;
		float GetAverageTime() const;
		float GetStandardDeviation() const;
		const std::string& GetName() const;

	private:
		// �ʿ信 ���� private ������ �޼��带 �߰��ϼ���.
		std::string mName;
		int* mWorkHours;
		size_t mMaxEntryCount;
		size_t mCurrentEntryCount;
		const int FAILED = -1;
	};
}
