#include "CircleLawn.h"

namespace lab5
{
	CircleLawn::CircleLawn(unsigned int radius)
		: Lawn()
		, mRadius(radius)
	{
	}

	CircleLawn::~CircleLawn()
	{
	}

	unsigned int CircleLawn::GetArea() const
	{
		const double PI = 3.14;

		unsigned int radiusSquare = mRadius * mRadius;
		double areaDouble = static_cast<double>(radiusSquare) * PI;

		return static_cast<unsigned int>(areaDouble + 0.5);
	}
}