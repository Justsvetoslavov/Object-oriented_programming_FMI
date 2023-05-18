#include "Circle.h"

const double PI = 3.1415;

Circle::Circle(int x, int y, double radius) : Shape(1), radius(radius) {
	setPoint(0, x, y);
}

double Circle::GetArea() const {
	return PI * radius * radius;
}

double Circle::GetPer() const {
	return 2 * PI * radius;
}

bool Circle::IsPointIn(int x, int y) const {
	return Point(x, y).getDist(getPointAtIndex(0)) <= radius;
}

Shape* Circle::clone() const override {
	return new Circle(*this);
}