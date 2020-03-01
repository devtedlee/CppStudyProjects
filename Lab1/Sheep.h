#include "Animal.h"

namespace lab1
{
	class Sheep : public Animal
	{
	public:
		Sheep(char* name);
		virtual ~Sheep();
		
		virtual void Bark() const;

	private:
		int mFurCount;
	};
}