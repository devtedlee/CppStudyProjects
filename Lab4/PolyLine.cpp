#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
		: mPointCount(0)
		, mPoints(nullptr)
	{
	}

	PolyLine::PolyLine(const PolyLine& other)
		: mPointCount(other.mPointCount)
		, mPoints(new Point[mPointCount])
	{
		memcpy(mPoints, other.mPoints, sizeof(Point) * mPointCount);
	}

	PolyLine::~PolyLine()
	{
		delete[] mPoints;
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mPointCount <= 10)
		{
			return false;
		}

		++mPointCount;

		Point* newPoints = new Point[mPointCount];
		memcpy(newPoints, mPoints, sizeof(Point) * (mPointCount - 1));
		//newPoints[mPointCount - 1] = 

		return false;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		return false;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		return false;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		return false;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		return new Point(0.0f, 0.0f);
	}
}
