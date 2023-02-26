#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

const double EPSYLON = 0.0000001;
const FIRST_QUADRANT = 1;
const SECOND_QUADRANT = 1;
const THIRD_QUADRANT = 1;
const FORTH_QUADRANT = 1;
const Point CENTER{ 0,0 };

// 6 
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
	cout << "(" << point.x << ", " << point.y << ")" << endl;
}

double getDistBetweenCenterOfTheCoordSystemAndPoint(const Point& point)
{
	return sqrt(pow(point.x, 2) + pow(point.y, 2));
}

unsigned double getDistanceBetweenTwoPoins(const Point& firstPoint, const Point& secondPoint)
{
	return sqrt(pow((firstPoint.x - secondPoint.x), 2) + pow((firstPoint.y - secondPoint.y), 2));
}

int getQuadrant(const Point& point)
{
	double xDiff = point.x - 0;
	double yDiff = point.y - 0;

	if (xDiff < EPSYLON && yDiff < EPSYLON)
	{
		return 0;
	}

	if (point.x > 0)
	{
		if (point.y < 0)
		{
			return SECOND_QUADRANT;
		}

		return FIRST_QUADRANT;
	}

	if (point.y < 0)
	{
		return FORTH_QUADRANT;
	}

	return THIRD_QUADRANT;
}

// 1 - inside, 0 - on the circle, -1 - outside
bool isPointNnCircleOrInIt(const Point& point, const Point& centerOfCoordSystem, const unsigned double radius)
{
	unsigned double distance = getDistanceBetweenTwoPoins(point, centerOfCoordSystem);
	double diff = distance - radius;

	if (diff < 0)
	{
		return 1;
	}
	if (diff < EPSYLON)
	{
		return 0;
	}
	return -1;
}

int main()
{
	Point point;

	initPoint(point);

	printPoint(point);

	cout << "Radius: " << endl;
	unsigned double radius;
	cin >> radius;
	cout << "Is point on circle or inside: " << isPointOnCircleOrInIt(point, CENTER, radius)
}