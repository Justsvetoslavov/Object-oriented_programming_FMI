#include <iostream>
#include <cmath>

using std::cin, std::cout, std::endl;

struct Point {
    int x;
    int y;
};

void createPoint(Point &p) {
    cout << "Enter x: ";
    cin >> p.x;
    cout << "Enter y: ";
    cin >> p.y;
}

void printPoint(const Point &p) {
    cout << "x: " << p.x << " y: " << p.y << endl;
}

double calculateDistance(const Point &p1, const Point &p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int calculateQuadrant(const Point &p) {
    if (p.x > 0 && p.y > 0) {
        return 1;
    } else if (p.x < 0 && p.y > 0) {
        return 2;
    } else if (p.x < 0 && p.y < 0) {
        return 3;
    } else if (p.x > 0 && p.y < 0) {
        return 4;
    }
    return 0;
}

void isInCircle(const double &radius, const Point &p) {
    double distance = calculateDistance({0, 0}, p);
    if (distance <= radius) {
        cout << "Point is in circle" << endl;
    } else {
        cout << "Point is not in circle" << endl;
    }
}

int main() {
    Point p1{};
    createPoint(p1);
    printPoint(p1);
    cout << "Quadrant: " << calculateQuadrant(p1) << endl;
    isInCircle(5, p1);
    Point p2{};
    createPoint(p2);
    printPoint(p2);
    cout << "Distance between p1 and p2: " << calculateDistance(p1, p2) << endl;
    return 0;
}
