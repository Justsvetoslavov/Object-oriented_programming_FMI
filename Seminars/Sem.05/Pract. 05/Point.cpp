#include "Point.h"
#include <cmath>

Point::Point(int x, int y) {
	setX(x);
	setY(y);
}

int Point::getX() const {
	return x;
}

int Point::getY() const {
	return y;
}

void Point::setX(int x) {
	this->x = x;
}

void Point::setY(int y) {
	this->y = y;
}

double Point::getDist(int a, int b, int c) {
	double mod = abs(a * x + b * y + c);
	double sq = sqrt(a * a + b * b);
	return mod / sq;
}
