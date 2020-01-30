#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
		: mPointCount(0)
	{
		memset(mPoints, 0, sizeof(Point*) * MAX_POINT_COUNT);
	}

	PolyLine::PolyLine(const PolyLine& other)
		: mPointCount(other.mPointCount)
	{
		memset(mPoints, 0, sizeof(Point*) * MAX_POINT_COUNT);
		memcpy(mPoints, other.mPoints, sizeof(Point*) * mPointCount);
	}

	PolyLine::~PolyLine()
	{
		Point** list = mPoints;
		for (size_t i = 0; i < mPointCount; ++i)
		{
			Point* deletePoint = *list;
			
			++list;
			
			delete deletePoint;
		}
	}

	PolyLine& PolyLine::operator=(const PolyLine& other)
	{
		mPointCount = other.mPointCount;
		memset(mPoints, 0, sizeof(Point*) * MAX_POINT_COUNT);
		memcpy(mPoints, other.mPoints, sizeof(Point*) * mPointCount);
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mPointCount >= MAX_POINT_COUNT)
		{
			return false;
		}

		Point* newPoint = new Point(x, y);

		mPoints[mPointCount] = newPoint;
		++mPointCount;

		return true;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		return AddPoint(point->GetX(), point->GetY());
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
		if (i >= mPointCount)
		{
			return nullptr;
		}

		return mPoints[i];
	}
}
