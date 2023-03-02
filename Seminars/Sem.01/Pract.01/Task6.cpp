#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

struct Point {
    double x;
    double y;

    void createPoint() {
        cout << "Enter X Y: ";
        cin >> x >> y;
    }

    void printPoint() {
        cout << "Point: (" << x << ", " << y << ")" << endl;
    }

    double distanceFromCenter() {
        return sqrt((x * x) + (y * y));
    }

    int getQuadrant() {
        if (x > 0 && y > 0) {
            return 1;
        } else if (x < 0 && y > 0) {
            return 2;
        } else if (x < 0 && y < 0) {
            return 3;
        } else if (x > 0 && y < 0) {
            return 4;
        }

        return 0;
    }
};

void isInTheCircle(double radius, Point& point) {
    double distanceToTheCenter = point.distanceFromCenter();

    if (distanceToTheCenter == radius) {
        cout << "Point is on the circle contour." << endl;
    } else if (distanceToTheCenter < radius) {
        cout << "Point is in the circle." << endl;
    } else {
        cout << "Point is out of the circle." << endl;
    }
} 

double distanceBetweenTwoPoints(Point* first, Point* second) {
    return sqrt(pow((first->x - second->x), 2) + pow(first->y - second->y, 2));
}

int main() {

    Point p;
    p.createPoint();
    p.printPoint();

    Point p1;
    p1.createPoint();
    p1.printPoint();

    cout << p.distanceFromCenter() << endl;
    cout << distanceBetweenTwoPoints(&p, &p1) << endl;
    cout << p.getQuadrant() << endl;
    cout << p1.getQuadrant() << endl;
    
    isInTheCircle(5, p);
    isInTheCircle(5, p1);


    return 0;
}