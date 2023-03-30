#include <iostream>
#include "Point.h"

int main() {

	int x, y;
	std::cin >> x >> y;

	Point p; // default constructor is overlapped with constructor with default parameters.

	Point p1(x, y);
	std::cout << p1.getX() << ", " << p1.getY() << "\n";
	p1.setX(5);
	p1.setY(7);

	p1.setX(0.25); // SetX/SetY for double parameters is deleted.

	Point p2 = 5; //convertion from number to Point is not allowed.

	std::cout << p1.getDist(4, 3, -2);
}

