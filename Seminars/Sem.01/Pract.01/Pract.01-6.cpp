#include <iostream>

struct Point {
	char name;
	double x;
	double y;
};

Point read() {
	Point p;
	std::cout << "point's name: ";
	std::cin >> p.name;

	std::cout << "x: ";
	std::cin >> p.x;

	std::cout << "y: ";
	std::cin >> p.y;

	return p;
}

void print(const Point& p) {
	std::cout << p.name << "(" << p.x << ", " << p.y << ")" << std::endl;
}

double distToStart(const Point& p2) {
	double x2 = p2.x * p2.x;
	double y2 = p2.y * p2.y;
	double dist = sqrt(x2 + y2);
	return dist;
}


double distBetween(const Point& p3, const Point& p4) {
	double dx = (p4.x - p3.x) * (p4.x - p3.x);
	double dy = (p4.y - p3.y) * (p4.y - p3.y);
	double dist = sqrt(dx + dy);
	return dist;
}

int whichQuadrant(const Point& p5) {
	if (p5.x > 0) {
		if (p5.y > 0) {
			return 1;
		}
		else if (p5.y < 0) {
			return 2;
		}
	}
	else if (p5.x < 0) {
		if (p5.y < 0) {
			return 3;
		}
		else if (p5.y > 0) {
			return 4;
		}
	}
	else return -1;
}

bool isIn(const Point& p6, double r) {
	double dist = p6.x * p6.x + p6.y * p6.y - r * r;
	if (dist < 0) return true;
	else if (dist == 0) return false;
}

int main() {
	Point p = read();
	print(p);

	Point p2 = read();
	std::cout << distToStart(p2);
	std::cout << std::endl;
	
	Point p3 = read();
	Point p4 = read();
	std::cout << distBetween(p3, p4);
	std::cout << std::endl;

	Point p5 = read();
	if (whichQuadrant(p5) == 1) std::cout << "first quadrant" << std::endl;
	else if(whichQuadrant(p5) == 2) std::cout << "second quadrant" << std::endl;
	else if (whichQuadrant(p5) == 3) std::cout << "third quadrant" << std::endl;
	else if (whichQuadrant(p5) == 4) std::cout << "fourth quadrant" << std::endl;
	else if (whichQuadrant(p5) == 0) std::cout << "origin" << std::endl;

	double r;
	std::cin >> r;
	Point p6 = read();
	if (isIn) std::cout << "the point is in the circle" << std::endl;
	else std::cout << "the point is on the circle" << std::endl;

}