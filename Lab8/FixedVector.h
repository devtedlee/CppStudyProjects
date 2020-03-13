#pragma once

using namespace std;

namespace lab8
{
	template<typename T, size_t N>
	class FixedVector
	{
	public:
		FixedVector();
		virtual ~FixedVector();

		bool Add(const T& t);
		bool Remove(const T& t);
		const T& Get(unsigned int index) const;
		T& operator[](unsigned int index) const;
		int GetIndex(const T& t) const;
		size_t GetSize() const;
		size_t GetCapacity();
	private:
		size_t mCount;
		T mArray[N];
	};
}