#include "RectangleLawn.h"

namespace lab5
{
	RectangleLawn::RectangleLawn(unsigned int width, unsigned int height)
		: Lawn()
		, mWidth(width)
		, mHeight(height)
	{
	}

	RectangleLawn::~RectangleLawn()
	{
	}

	unsigned int RectangleLawn::GetArea() const
	{
		return mHeight * mWidth;
	}

	unsigned int RectangleLawn::GetMinimumFencesCount() const
	{
		unsigned int circumferenceLength = mWidth * 2 + mHeight * 2;

		return circumferenceLength * 4;
	}

	unsigned int RectangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		unsigned int fencesCount = GetMinimumFencesCount();

		double fencePriceDollor = static_cast<double>(fencesCount)* static_cast<double>(fenceType) / 4;

		unsigned int price = static_cast<unsigned int>(fencePriceDollor);
		if (fencePriceDollor == static_cast<double>(price))
		{
			return price;
		}

		return price + 1;
	}
}