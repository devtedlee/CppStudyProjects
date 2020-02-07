#pragma once

#include "Lawn.h"
#include "IFenceable.h"

namespace lab5
{
	class EquilateralTriangleLawn : public Lawn, public IFenceable
	{
	public:
		EquilateralTriangleLawn(unsigned int sideLength);
		virtual ~EquilateralTriangleLawn();

		unsigned int GetArea() const;
		unsigned int GetMinimumFencesCount() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;
	private:
		unsigned int mSideLength;
	};
}