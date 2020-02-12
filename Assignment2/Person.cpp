#include "Person.h"

namespace assignment2
{
	Person::Person(const char* name, unsigned int weight)
		: mWeight(weight)
		, mName(new std::string(name))
	{
	}

	Person::~Person()
	{
		delete mName;
	}

	const std::string& Person::GetName() const
	{
		return *mName;
	}

	unsigned int Person::GetWeight() const
	{
		return mWeight;
	}
}
