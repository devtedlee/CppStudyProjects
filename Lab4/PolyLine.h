#pragma once

#include "Point.h"

namespace lab4
{
	class PolyLine
	{
	public:
		PolyLine();
		PolyLine(const PolyLine& other);
		~PolyLine();

		PolyLine& operator=(const PolyLine& other);
		bool AddPoint(float x, float y);
		bool AddPoint(const Point* point);
		bool RemovePoint(unsigned int i);
		bool TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const;

		const Point* operator[](unsigned int i) const;
	private:
		enum {
			MAX_POINT_COUNT = 10
		};
		Point* mPoints[MAX_POINT_COUNT];
		size_t mPointCount;
	};
}
