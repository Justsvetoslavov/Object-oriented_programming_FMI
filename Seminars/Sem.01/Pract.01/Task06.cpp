#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

struct Point
{
	double x;
	double y;
};

void inputPoint(Point& point)
{
	cout << "Enter the coordinates of the point (x,y): ";
	cin >> point.x >> point.y;
}

void printPoint(const Point& point)
{
	cout << "(" << point.x << ", " << point.y << ")" << endl;
}

double distanceToCenter(const Point& point)
{
	return sqrt(point.x * point.x + point.y * point.y);
}

double distanceTo(const Point& first, const Point& second)
{
	double dx = first.x - second.x;
	double dy = first.y - second.y;
	return sqrt(dx * dx + dy * dy);
}

int quadrant(const Point& point)
{
	if (point.x > 0 && point.y > 0){
		return 1;
	}
	else if (point.x < 0 && point.y > 0) {
		return 2;
	}
	else if (point.x < 0 && point.y < 0) {
		return 3;
	}
	else if (point.x > 0 && point.y < 0) {
		return 4;
	}
	else {
		return 0;
	}
}

char isInsideCircle(const Point& point, double r)
{
	double distance = distanceToCenter(point);
	if (distance < r)
		cout << "The point is inside the circle.";
	else if (distance == r)
		cout << "The point is on the contour.";
	else
		cout << "The point is outside the circle.";

	return 0;
}

int main()
{
	Point p1;
	cout << "Point #1" << endl;;
	inputPoint(p1);
	printPoint(p1);
	cout << "The distance from the center to the point is: ";
	cout << distanceToCenter(p1) << endl;
	cout << "The quadrant of the point is " << quadrant(p1) << "." << endl << endl;

	cout << "Point #2: " << endl;
	Point p2;
	inputPoint(p2);
	printPoint(p2);
	cout << "The distance from the center to the point is: ";
	cout << distanceToCenter(p2) << endl;
	cout << "The quadrant of the point is " << quadrant(p2) << "." << endl << endl;

	cout << "The distance between the two points is: ";
	cout << distanceTo(p1, p2) << endl;

	double r;
	cout << "Enter the radius of the circle: ";
	cin >> r;
	cout << "Point #1" << endl;
	char result1 = isInsideCircle(p1, r);
	cout << result1 << endl;
	cout << "Point #2" << endl;
	char result2 = isInsideCircle(p2, r);
	cout << result2 << endl;

	return 0;
}