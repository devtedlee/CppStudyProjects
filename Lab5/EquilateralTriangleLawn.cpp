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
		double areaDouble = pow(mSideLength, 2) / 4.0 * sqrt(3);

		return static_cast<unsigned int>(areaDouble + 0.5);
	}

	unsigned int EquilateralTriangleLawn::GetMinimumFencesCount() const
	{
		return mSideLength * 12;
	}

	unsigned int EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		unsigned int fencesCount = GetMinimumFencesCount();

		double fencePriceDollor = static_cast<double>(fencesCount) * static_cast<double>(fenceType) / 4;

		unsigned int price = static_cast<unsigned int>(fencePriceDollor);
		if (fencePriceDollor == static_cast<double>(price))
		{
			return price;
		}

		return price + 1;
	}
}