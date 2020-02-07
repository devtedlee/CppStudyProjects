#include "SquareLawn.h"

namespace lab5
{
	SquareLawn::SquareLawn(unsigned int width)
		: Lawn()
		, mWidth(width)
	{
	}

	SquareLawn::~SquareLawn()
	{
	}

	unsigned int SquareLawn::GetArea() const
	{
		return mWidth * mWidth;
	}

	unsigned int SquareLawn::GetMinimumFencesCount() const
	{
		return 0;
	}
	unsigned int SquareLawn::GetFencePrice(eFenceType fenceType) const
	{
		return 0;
	}
}