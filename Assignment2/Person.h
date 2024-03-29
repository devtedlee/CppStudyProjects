#pragma once

#include <string>

namespace assignment2
{
	class Person
	{
	public:
		Person(const char* name, unsigned int weight);
		virtual ~Person();
		Person(const Person& other);

		Person& operator=(const Person& other);
		const std::string& GetName() const;
		unsigned int GetWeight() const;

	private:
		std::string mName;
		unsigned int mWeight;
	};
}
