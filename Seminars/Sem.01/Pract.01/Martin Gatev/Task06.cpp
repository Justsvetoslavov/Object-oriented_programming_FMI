#include <iostream>

using std::cin;
using std::cout;

struct Point
{
	double x;
	double y;
};

void initPoint(Point& point)
{
	cin >> point.x >> point.y;
}

void printPoint(const Point& point)
{
	cout << "(" << point.x << ", " << point.y << ")" << std::endl;
}

double distanceFromZero(const Point& point)
{
	return sqrt(point.x * point.x + point.y * point.y);
}

double DistanceBetweenTwoPoints(const Point& p1, const Point& p2)
{
	double dx = p1.x - p2.x;

	double dy = p1.y - p2.y;

	return sqrt(dx * dx + dy * dy);
}

int PointQuadrant(const Point& p1)
{
	if (p1.x > 0 && p1.y > 0)
	{
		return 1;
	}
	else if (p1.x < 0 && p1.y > 0)
	{
		return 2;
	}
	else if (p1.x < 0 && p1.y < 0)
	{
		return 3;
	}
	else if (p1.x > 0 && p1.y < 0)
	{
		return 4;
	}
	else
	{
		return -1;
	}
}

int isInsideTheCircle(const double radius, const Point& p1)
{
	double distanceFromCenterToPoint = distanceFromZero(p1);

	if (distanceFromCenterToPoint < radius)
	{
		return 1;
	}
	if (distanceFromCenterToPoint - radius <= 0.00001)
	{
		return 0;
	}

	return -1;

}