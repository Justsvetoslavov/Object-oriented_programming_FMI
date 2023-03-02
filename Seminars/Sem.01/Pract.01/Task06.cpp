#include <iostream>

namespace Points {
	struct Point {
		int x;
		int y;
	};

	void ReadPoint(Point& point) {
		std::cout << "Enter x: ";
		std::cin >> point.x;
		std::cout << "Enter y: ";
		std::cin >> point.y;
	}

	void PrintPoint(const Point& point) {
		std::cout << "(" << point.x << "," << point.y << ")" << std::endl;
	}

	double GetDistBetweenTwoPoints(const Point& p1, const Point& p2) {
		double dx = p1.x - p2.x;
		double dy = p1.y - p2.y;

		return sqrt(dx * dx + dy * dy);
	}

	double GetDistFromOriginToPoint(const Point& point) {
		return sqrt(point.x * point.x + point.y * point.y);
	}

	int GetQuadrant(const Point& point) {
		if (point.x >= 0 && point.y >= 0) {
			return 1;
		}

		if (point.x < 0 && point.y > 0) {
			return 2;
		}

		if (point.x < 0 && point.y < 0) {
			return 3;
		}

		if (point.x > 0 && point.y < 0) {
			return 4;
		}
	}

	int GetPointToCirclePosition(const Point& point, int radius) {
		double epsilon = 0.00001;
		if (abs(GetDistFromOriginToPoint(point) < epsilon)) {
			return 1;
		}
		else if (abs(GetDistFromOriginToPoint(point) > radius)) {
			return 2;
		}
		return 3;

	}
}

int main()
{
	using namespace Points;

	Point point1;
	ReadPoint(point1);

	Point point2;
	ReadPoint(point2);

	std::cout << "Distance between first and second point: " 
		<< GetDistBetweenTwoPoints(point1, point2) << std:: endl;

	std::cout << "Distance from origin to first point: "
		<< GetDistFromOriginToPoint(point1) << std::endl;
	std::cout << "Distance from origin to second point: " 
		<< GetDistFromOriginToPoint(point2) << std::endl;

	std::cout << "First point is in " << GetQuadrant(point1) << " quadrant" << std::endl;
	std::cout << "Second point is in " << GetQuadrant(point2) << " quadrant" << std::endl;

	int firstPointPosition = GetPointToCirclePosition(point1, 3);

	if (firstPointPosition == 1) {
		std::cout << "Point is on outline of the circle" << std::endl;
	}
	else if (firstPointPosition == 2) {
		std::cout << "Point is out of the circle" << std::endl;
	}
	else if (firstPointPosition == 3) {
		std::cout << "Point is in the circle" << std::endl;
	}

}