#pragma once

#include "SquareLawn.h"
#include "IFenceable.h"

namespace lab5
{
	class RectangleLawn : public SquareLawn
	{
	public:
		RectangleLawn(unsigned int width, unsigned int height);
		virtual ~RectangleLawn();

		unsigned int GetArea() const;
	private:
		unsigned int mHeight;
	};
}