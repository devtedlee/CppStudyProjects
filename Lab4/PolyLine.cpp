#include <cstring>
#include <cmath>
#include <cfloat>
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
		
		for (size_t i = 0; i < mPointCount; ++i)
		{
			mPoints[i] = new Point(*(other.mPoints[i]));
		}
	}

	PolyLine::~PolyLine()
	{
		for (size_t i = 0; i < mPointCount; ++i)
		{
			const Point* deletePoint = mPoints[i];

			delete deletePoint;
		}
	}

	PolyLine& PolyLine::operator=(const PolyLine& other)
	{
		if (mPoints - other.mPoints == 0)
		{
			return *this;
		}

		for (size_t i = 0; i < mPointCount; ++i)
		{
			const Point* deletePoint = mPoints[i];

			delete deletePoint;
		}

		mPointCount = other.mPointCount;
		memset(mPoints, 0, sizeof(Point*) * MAX_POINT_COUNT);

		for (size_t i = 0; i < mPointCount; ++i)
		{
			mPoints[i] = new Point(*(other.mPoints[i]));
		}

		return *this;
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mPointCount >= MAX_POINT_COUNT)
		{
			return false;
		}

		mPoints[mPointCount] = new Point(x, y);
		++mPointCount;

		return true;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (point == nullptr || mPointCount >= MAX_POINT_COUNT)
		{
			return false;
		}

		mPoints[mPointCount] = point;
		++mPointCount;

		return true;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (mPointCount == 0 || mPointCount >= MAX_POINT_COUNT || i >= mPointCount)
		{
			return false;
		}

		delete mPoints[i];

		for (unsigned int j = i; j < mPointCount - 1; ++j)
		{
			mPoints[j] = mPoints[j + 1];
		}
		mPoints[mPointCount - 1] = nullptr;

		--mPointCount;

		return true;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		//validate mPoints that has no point and one point
		if (mPointCount < 1)
		{
			return false;
		}

		float minX = FLT_MAX;
		float minY = FLT_MAX;
		float maxX = FLT_MIN;
		float maxY = FLT_MIN;
		for (size_t i = 0; i < mPointCount; ++i)
		{
			const Point* pointsP = mPoints[i];
			float x = pointsP->GetX();
			float y = pointsP->GetY();
			float temp;

			temp = fminf(minX, x);
			if (temp == x)
			{
				minX = x;
			}
			temp = fminf(minY, y);
			if (temp == y)
			{
				minY = y;
			}

			temp = fmaxf(maxX, x);
			if (temp == x)
			{
				maxX = x;
			}
			temp = fmaxf(maxY, y);
			if (temp == y)
			{
				maxY = y;
			}
		}

		//validate variables can make proper rectangle
		if (minX == maxX || minY == maxY || minX == maxY || minY == maxX)
		{
			return false;
		}

		outMin->SetX(minX);
		outMin->SetY(minY);
		outMax->SetX(maxX);
		outMax->SetY(maxY);

		return true;
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
