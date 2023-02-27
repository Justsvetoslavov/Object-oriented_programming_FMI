#include <iostream>
#include <cmath>

const double EPSILON = 0.0001;
struct Point {
	double x;
	double y;
};

void initializePoint(Point& point)
{
	std::cout << "Enter x: ";
	std::cin >> point.x;
	std::cout << "Enter y: ";
	std::cin >> point.y;
}

void printPoint(const Point& point)
{
	std::cout << "x: " << point.x << ", y: " << point.y << std::endl;
}

double calculateDist(const Point& point1, const Point& point2)
{
	return sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));
}

int calculateQuadrant(const Point& point)
{
	if (point.x > EPSILON)
	{
		if (point.y > EPSILON)
			return 1;
		else
			return 4;
	}
	else
	{
		if (point.y > EPSILON)
			return 2;
		else
			return 3;
	}
}

bool isInCircle(const double& radius, const Point& point)
{
	double distance = calculateDist({ 0,0 }, point);
	if (radius - distance > -EPSILON)
	{
		return true;
	}
	return false;
}

int main()
{
	Point p1{};
	Point p2{2, 6};
	initializePoint(p1);
	printPoint(p1);
	std:: cout << "Distance from the centre to p1 is: " << calculateDist({0.0, 0.0}, p1) << std::endl;
	std::cout << "Distance between p1 and p2 is: " << calculateDist(p2, p1) << std::endl;

	std::cout << "Quadrant: " << calculateQuadrant(p1) << std::endl;
	std::cout << "Quadrant: " << calculateQuadrant({ -3, 9 }) << std::endl;
	std::cout << "Quadrant: " << calculateQuadrant({ -3, -9 }) << std::endl;
	std::cout << "Quadrant: " << calculateQuadrant({ 0.7, -0.003 }) << std::endl;

	std::cout << "The point is in the circle: " << isInCircle(9, p1) << std::endl;
}