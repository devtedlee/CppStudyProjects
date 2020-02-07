#include "RectangleLawn.h"

namespace lab5
{
	RectangleLawn::RectangleLawn(unsigned int width, unsigned int height)
		: SquareLawn(width)
		, mHeight(height)
	{
	}

	RectangleLawn::~RectangleLawn()
	{
	}

	unsigned int RectangleLawn::GetArea() const
	{
		return mHeight * SquareLawn::GetWidth();
	}
}