#pragma once

namespace lab4
{
	class Point
	{
	public:
		Point();
		Point(float x, float y);
		Point(const Point& other);
		~Point();

		Point& operator=(const Point& other);
		Point operator+(const Point& other) const;
		Point operator-(const Point& other) const;
		float Dot(const Point& other) const;
		Point operator*(float operand) const;

		float GetX() const;
		float GetY() const;
	private:
		float mX;
		float mY;
	};
}
