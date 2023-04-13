#include "Point.h"
#include <cmath>

Point::Point(int x, int y) {
	SetX(x);
	SetY(y);
}

int Point::GetX() const {
	return x;
}

int Point::GetY() const {
	return y;
}

void Point::SetX(int x) {
	this->x = x;
}

void Point::SetY(int y) {
	this->y = y;
}

double Point::GetDistance(int a, int b, int c) const {
	int numerator = a * this->x + b * this->y + c;
	double denominator = sqrt(a * a + b * b);
	return abs(numerator / denominator);
}
