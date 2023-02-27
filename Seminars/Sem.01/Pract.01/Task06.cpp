#include <iostream>
using namespace std;

struct Point {
	int x;
	int y;
};

void ReadPoint(Point&);
void PrintPoint(Point);
double GetDistanceFromCenter(Point);
double GatDistanceBetweenPoints(Point, Point);
int GetPointQuadrant(Point);
bool IsPointInCircleWithCenter00(Point, size_t);

int main() {

}

void ReadPoint(Point& p) {
	cout << "x: ";
	cin >> p.x;
	cout << "y: ";
	cin >> p.y;
}

void PrintPoint(Point p) {
	cout << "x: " << p.x;
	cout << "y: " << p.y;
}

double GetDistanceFromCenter(Point p) {
	return sqrt(p.x * p.x + p.y * p.y);
}

double GetDistanceBetweenPoints(Point p1, Point p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int GetPointQuadrant(Point p) {
	if (p.x > 0)
	{
		if (p.y > 0) return 1;
		else if (p.y < 0) return 4;
	}
	else if (p.x < 0) {
		if (p.y > 0) return 2;
		else if (p.y < 0) return 3;
	}
	return 0;
}

bool IsPointInCircleWithCenter00(Point p, size_t radius) {
	return GetDistanceFromCenter(p) <= radius;
}