#pragma once

#include "Lawn.h"
#include "IFenceable.h"

namespace lab5
{
	class RectangleLawn : public Lawn, public IFenceable
	{
	public:
		RectangleLawn(unsigned int width, unsigned int height);
		~RectangleLawn();

		virtual unsigned int GetArea() const = 0;
		virtual unsigned int GetMinimumFencesCount() const = 0;
		virtual unsigned int GetFencePrice(eFenceType fenceType) const = 0;
	private:
		unsigned int mWidth;
		unsigned int mHeight;
	};
}