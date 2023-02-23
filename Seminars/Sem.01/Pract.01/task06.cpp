#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    int x;
    int y;

    void create() {
        cout << "Enter x: ";
        cin >> x;
        cout << "Enter y: ";
        cin >> y;
    }

    void print() {
        cout << "x: " << x << " y: " << y << endl;
    }

    double calculateDistance(const Point p) {
        return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    }

    int calculateQuadrant() {
        if (x > 0 && y > 0) {
            return 1;
        } else if (x < 0 && y > 0) {
            return 2;
        } else if (x < 0 && y < 0) {
            return 3;
        } else if (x > 0 && y < 0) {
            return 4;
        }
    }

    void isInCircle(const double radius) {
        double distance = calculateDistance({0, 0});
        if (distance <= radius) {
            cout << "Point is in circle" << endl;
        } else {
            cout << "Point is not in circle" << endl;
        }
    }
};

int main() {
    Point p1;
    p1.create();
    p1.print();
    cout << "Quadrant: " << p1.calculateQuadrant() << endl;
    p1.isInCircle(5);
    Point p2;
    p2.create();
    p2.print();
    cout << "Distance between p1 and p2: " << p2.calculateDistance(p1) << endl;
    return 0;
}
