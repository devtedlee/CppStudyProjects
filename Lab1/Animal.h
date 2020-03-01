#pragma once

namespace lab1
{
	class Animal
	{
	public:
		Animal(char* name);
		virtual ~Animal();

		virtual void Bark() const = 0;
		inline char* GetName() const;

	private:
		char* mName;
	};

	char* Animal::GetName() const
	{
		return mName;
	}
}
