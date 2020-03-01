#include <iostream>
#include "Sheep.h"

namespace lab1
{
	Sheep::Sheep(char* name)
		: Animal(name)
		, mFurCount(0)
	{

	};

	Sheep::~Sheep()
	{
	}

	void Sheep::Bark() const
	{
		std::cout << Animal::GetName() << ": MEA~" << std::endl;
	}
}