#include "Trailer.h"

namespace assignment2
{
	Trailer::Trailer(unsigned int weight)
		: mWeight(weight)
	{
	}

	unsigned int Trailer::GetWeight() const
	{
		return mWeight;
	}
}
