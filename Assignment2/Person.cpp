#include "Person.h"

namespace assignment2
{
	Person::Person(const char* name, unsigned int weight)
		: mWeight(weight)
		, mName(name)
	{
	}

	Person::~Person()
	{
	}

	Person::Person(const Person& other)
		: mWeight(other.mWeight)
		, mName(other.mName)
	{
	}

	Person& Person::operator=(const Person& other)
	{
		if (this == &other)
		{
			return *this;
		}
		mWeight = other.mWeight;

		mName = std::string(other.mName);

		return *this;
	}

	const std::string& Person::GetName() const
	{
		return mName;
	}

	unsigned int Person::GetWeight() const
	{
		return mWeight;
	}
}
