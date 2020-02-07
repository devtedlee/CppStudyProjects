#include <cmath>
#include "EquilateralTriangleLawn.h"

namespace lab5
{
	EquilateralTriangleLawn::EquilateralTriangleLawn(unsigned int sideLength)
		: Lawn()
		, mSideLength(sideLength)
	{
	}

	EquilateralTriangleLawn::~EquilateralTriangleLawn()
	{
	}

	unsigned int EquilateralTriangleLawn::GetArea() const
	{
		double sideSquare = pow(mSideLength, 2);
		double areaDouble = sideSquare * sqrt(3) / 4.0;

		unsigned int area = static_cast<unsigned int>(areaDouble);
		if (areaDouble == static_cast<double>(area))
		{
			return area;
		}

		return area + 1;
	}

	unsigned int EquilateralTriangleLawn::GetMinimumFencesCount() const
	{
		return 0;
	}

	unsigned int EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		return 0;
	}
}