#include <iostream>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;

struct Point {
    double x, y;
};

void initPoint(Point& p)
{
    cout << "x = ";
    cin >> p.x;
    cout << "y = ";
    cin >> p.y;
}

void printPoint(Point& p)
{
    cout << p.x << " ";
    cout << p.y;
}

double distanceToCenter(Point& p)
{
    return sqrt(p.x * p.x + p.y * p.y);
}

double distanceTo(const Point& p1, const Point& p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

int quadrant(Point& p)
{
    if (p.x > 0 && p.y > 0) {
        return 1;
    }
    else if (p.x < 0 && p.y > 0) {
        return 2;
    }
    else if (p.x < 0 && p.y < 0) {
        return 3;
    }
    else if (p.x > 0 && p.y < 0) {
        return 4;
    }
    else {
        return 0;
    }
}

int main()
{
    Point p;
    initPoint(p);
    cout << "Point 1:";
    printPoint(p);
    cout << endl;
    cout << "Distance from start: " << distanceToCenter(p) << endl;
    Point q;
    cout << "Point 2:";
    initPoint(q);
    cout << "Distance between the two points: " << distanceTo(p, q) << endl;
    cout << "The point is in quadrant: " << quadrant(p) << endl;
}

