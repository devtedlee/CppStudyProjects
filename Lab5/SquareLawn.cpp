#include "SquareLawn.h"

namespace lab5
{
	SquareLawn::SquareLawn(unsigned int width)
		: RectangleLawn(width, width)
	{
	}

	SquareLawn::~SquareLawn()
	{
	}

	unsigned int SquareLawn::GetArea() const
	{
		unsigned int width = RectangleLawn::GetWidth();
		return width * width;
	}

	unsigned int SquareLawn::GetMinimumFencesCount() const
	{
		unsigned int width = RectangleLawn::GetWidth();
		return width * 16;
	}
}