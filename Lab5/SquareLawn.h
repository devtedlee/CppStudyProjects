#pragma once

#include "Lawn.h"
#include "IFenceable.h"

namespace lab5
{
	class SquareLawn : public Lawn, public IFenceable
	{
	public:
		SquareLawn(unsigned int width);
		virtual ~SquareLawn();

		virtual unsigned int GetArea() const;
		unsigned int GetMinimumFencesCount() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;
		inline unsigned int GetWidth() const;
	private:
		unsigned int mWidth;
	};

	unsigned int SquareLawn::GetWidth() const
	{
		return mWidth;
	}
}