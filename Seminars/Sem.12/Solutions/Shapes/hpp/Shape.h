#pragma once

#include <iostream>

class Shape {
private:
	Point* points = nullptr;
	size_t pointsCount = 0;
protected:
	struct Point {
		int x = 0, y = 0;	

		Point() = default;
		Point(int x, int y) : x(x), y(y) {}

		double GetDist(const point& other) const {
			int dx = x - other.x;
			int dy = y - other.y;

			return sqrt(dx * dx + dy * dy);
		}
	};
	
	void SetPoint(size_t pointIndex, int x, int y);
	const Point& GetPointAtIndex(size_t index) const;
public:
	Shape() = default;
	explicit Shape(size_t pointsCount);
	Shape(const Shape& other);
	Shape& operator=(const Shape& other);
	virtual ~Shape();

	virtual double GetArea() const = 0;
	virtual double GetPer()  const = 0; 
	virtual bool IsPointIn(int x, int y) const = 0;

	virtual Shape* clone() const = 0;
private:	
	void CopyFrom(const Shape& other);
	void Free();
};