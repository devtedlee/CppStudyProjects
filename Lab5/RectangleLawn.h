#pragma once

#include "Lawn.h"
#include "IFenceable.h"

namespace lab5
{
	class RectangleLawn : public Lawn, public IFenceable
	{
	public:
		RectangleLawn(unsigned int width, unsigned int height);
		virtual ~RectangleLawn();

		virtual unsigned int GetArea() const;
		unsigned int GetMinimumFencesCount() const;
		virtual unsigned int GetFencePrice(eFenceType fenceType) const;
		inline unsigned int GetWidth() const;
	private:
		unsigned int mWidth;
		unsigned int mHeight;
	};

	unsigned int RectangleLawn::GetWidth() const
	{
		return mWidth;
	}
}