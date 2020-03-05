#pragma once

namespace lab1
{
	class Animal
	{
	public:
		Animal(char* name);
		virtual ~Animal();
		Animal(Animal& other);

		virtual void Bark() const = 0;
		inline char* GetName() const;

	private:
		char* mName;
		int* mAge;
	};

	char* Animal::GetName() const
	{
		return mName;
	}
}
