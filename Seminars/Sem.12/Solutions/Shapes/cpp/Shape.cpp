#include "Shape.h"

const Shape::point& Shape::GetPointAtIndex(size_t index) const
{
	if (index >= pointsCount) {
		throw std::out_of_range("Invalid index!");
	}

	return  points[index];
}

void Shape::SetPoint(size_t pointIndex, int x, int y)
{
	if (pointIndex >= pointsCount) {
		throw std::out_of_range("Invalid index!");
	}

	points[pointIndex] = point(x, y);
}

Shape::Shape(size_t pointsCount) : pointsCount(pointsCount) {
	points = new point[pointsCount]; // [0,0], [0,0]....
}

Shape::Shape(const Shape& other) {
	copyFrom(other);
}

Shape& Shape::operator= (const Shape& other) {
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}

Shape::~Shape() {
	Free();
}

void Shape::CopyFrom(const Shape& other) {
	points = new point[other.pointsCount];
	
	for (size_t i = 0; i < other.pointsCount; ++i) {
		points[i] = other.points[i];
	}
	
	pointsCount = other.pointsCount;
}

void Shape::Free() {
	delete[] points;
}
