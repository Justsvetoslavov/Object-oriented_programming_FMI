#include "Point.h"
#include <cmath>

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Point::GetX() const
{
	return x;
}

int Point::GetY() const
{
	return y;
}

void Point::SetX(int x)
{
	this->x = x;
}

void Point::SetY(int y)
{
	this->y = y;
}

//used chat gpt for this one
int Point::Distance(const Point& p1, const Point& p2) const
{
	double numerator = abs((p2.y - p1.y) * x - (p2.x - p1.x) * y + p2.x * p1.y - p2.y * p1.x);
	double denominator = sqrt(pow(p2.y - p1.y, 2) + pow(p2.x - p1.x, 2));

	return numerator / denominator;
}



