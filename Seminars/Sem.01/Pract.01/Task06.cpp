#include <iostream>
#include <cmath>

struct Point {
	double x;
	double y;
};

struct Circle {
	double radius;
	Point center = { 0, 0 };
};

void inputPoint(Point& p) {
	std::cin >> p.x >> p.y;
}

void printPoint(const Point& p) {
	std::cout << p.x << " " << p.y << "\n";
}

double getDistanceToOrigin(const Point& p) {
	return sqrt(p.x * p.x + p.y * p.y);
}

double getDistanceBetweenPoints(const Point& p1, const Point& p2) {
	double dx = p1.x - p2.x;
	double dy = p1.y - p2.y;

	return sqrt(dx * dx + dy * dy);
}

int getQuadrant(const Point& p) {
	// 1 or 4
	if (p.x > 0) {
		//x is +, y is +
		if (p.y > 0) return 1;
		//x is +, y is -
		return 4;
	}
	else {
		//x is -, y is +
		if (p.y > 0) return 2;
		//x is -, y is -
		return 3;
	}
}

//This function will return -1 if the point is outside the circle,
//0 if it's on the outline and 1 if it's on the inside of the circle 
int posRelativeToCircle(const Point& p, const Circle& c) {
	//The center of the cirlce is the origin
	double dist = getDistanceToOrigin(p);
	double epsilon = 0.00001;
	//Distance to origin is equal to the radius => the point is on the circle outline
	if (abs(dist - c.radius) < epsilon) {
		return 0;
	}
	else if (dist > c.radius) {
		return -1;
	}
	return 1;
}

int main()
{
	const int NUMBER_OF_POINTS = 5;
	Circle c = { 10 };
	Point points[NUMBER_OF_POINTS];
	for (int i = 0; i < NUMBER_OF_POINTS; i++) {
		inputPoint(points[i]);
	}

	std::cout << "Distance to origin for each point:\n";
	for (int i = 0; i < NUMBER_OF_POINTS; i++) {
		std::cout << getDistanceToOrigin(points[i]) << " ";
	}

	std::cout << "\nQuadrant for each point:\n";
	for (int i = 0; i < NUMBER_OF_POINTS; i++) {
		std::cout << getQuadrant(points[i]) << " ";
	}

	std::cout << "\nPos relative to circle for each point:\n";
	for (int i = 0; i < NUMBER_OF_POINTS; i++) {
		switch (posRelativeToCircle(points[i], c)) {
		case -1: std::cout << "Outside circle "; break;
		case 0: std::cout << "On outline "; break;
		case 1: std::cout << "Inside circle "; break;
		}
	}
}

