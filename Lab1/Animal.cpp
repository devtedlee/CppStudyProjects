#include <cstring>
#include "Animal.h"

namespace lab1
{
	Animal::Animal(char* name)
	{
		size_t nameLen = strlen(name);
		if (nameLen == 0)
		{
			mName = new char[7];
			strcpy(mName, "NONAME");
		}
		else
		{
			mName = new char[nameLen + 1];
			strncpy(mName, name, nameLen + 1);
			mName[nameLen] = '\0';
		}
	}

	Animal::Animal(Animal& other)
		: mName(nullptr)
		, mAge(nullptr)
	{
		mAge = new int(other.mAge);
	}

	Animal::~Animal()
	{
		delete[] mName;
	}
}