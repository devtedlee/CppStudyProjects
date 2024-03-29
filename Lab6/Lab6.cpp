#include "Lab6.h"

namespace lab6
{
	int Sum(const std::vector<int>& v)
	{
		size_t vSize = v.size();
		int sum = 0;
		for (size_t i = 0; i < vSize; ++i)
		{
			sum += v[i];
		}

		return sum;
	}

	int Min(const std::vector<int>& v)
	{
		int min = INT_MAX;
		size_t vSize = v.size();

		for (size_t i = 0; i < vSize; ++i)
		{
			if (v[i] < min)
			{
				min = v[i];
			}
		}

		return min;
	}

	int Max(const std::vector<int>& v)
	{
		int max = INT_MIN;
		size_t vSize = v.size();

		for (size_t i = 0; i < vSize; ++i)
		{
			if (v[i] > max)
			{
				max = v[i];
			}
		}

		return max;
	}

	float Average(const std::vector<int>& v)
	{
		size_t vSize = v.size();
		if (vSize == 0)
		{
			return 0.f;
		}

		int sum = Sum(v);
		if (sum == 0)
		{
			return 0.f;
		}

		return static_cast<float>(sum) / static_cast<float>(vSize);
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		size_t vSize = v.size();
		std::vector<int> v2(vSize, 0);

		for (size_t i = 0; i < vSize; ++i)
		{
			for (size_t j = i + 1; j < vSize; ++j)
			{
				if (v[i] == v[j])
				{
					v2[i] = v2[i] + 1;
				}
			}
		}

		int result = 0;
		int resultIndex = 0;
		int max = INT_MIN;
		for (size_t i = 0; i < vSize; ++i)
		{
			if (v2[i] > max)
			{
				max = v2[i];
				resultIndex = i;
			}
		}

		if (max != INT_MIN)
		{
			result = v[resultIndex];
		}

		return result;
	}

	void SortDescending(std::vector<int>& v)
	{
		size_t vSize = v.size();
		
		for (size_t i = 0; i < vSize; ++i)
		{
			int max = v[i];
			size_t maxIndex = i;
			for (size_t j = i + 1; j < vSize; ++j)
			{
				if (v[j] > max)
				{
					max = v[j];
					maxIndex = j;
				}
			}

			int temp = v[i];
			v[i] = v[maxIndex];
			v[maxIndex] = temp;
		}
	}
}
