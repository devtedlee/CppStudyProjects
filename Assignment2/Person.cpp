#include "Person.h"

namespace assignment2
{
	Person::Person(const char* name, unsigned int weight)
		: mWeight(weight)
	{
		size_t name_len = strlen(name);
		mName = new char[name_len + 1];
		strncpy(mName, name, name_len + 1);
		mName[name_len] = '\0';
	}

	Person::~Person()
	{
		delete[] mName;
	}

	Person::Person(const Person& other)
		: mWeight(other.mWeight)
	{
		delete[] mName;
		size_t name_len = strlen(other.mName);
		mName = new char[name_len + 1];
		strncpy(mName, other.mName, name_len + 1);
		mName[name_len] = '\0';
	}

	Person& Person::operator=(const Person& other)
	{
		if (this == &other)
		{
			return *this;
		}
		mWeight = other.mWeight;

		delete[] mName;
		size_t name_len = strlen(other.mName);
		mName = new char[name_len + 1];
		strncpy(mName, other.mName, name_len + 1);
		mName[name_len] = '\0';

		return *this;
	}

	const std::string& Person::GetName() const
	{
		std::string* name = new std::string(mName);
		return *name;
	}

	unsigned int Person::GetWeight() const
	{
		return mWeight;
	}
}
