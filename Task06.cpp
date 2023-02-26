#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

struct Point {
    int x, y;
};

void read_point(const Point &p) {
    cout << "X: " << p.x << endl
         << "Y: " << p.y << endl;
}

void write(Point& p) {
    cin >> p.x >> p.y;
}

void distance_from_zero(const Point& p) {
    cout << sqrt(p.x * p.x + p.y * p.y) << endl;
}

void distance_between_points(const Point& a, const Point& b) {
    cout << sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)) << endl;
}

void quadrant(const Point& p) {
    if (p.x > 0 && p.y > 0)
        cout << "I\n";
    else if (p.x < 0 && p.y > 0)
        cout << "II\n";
    else if (p.x < 0 && p.y < 0)
        cout << "III\n";
    else if (p.x > 0 && p.y < 0)
        cout << "IV\n";
    else if (p.x == 0 && p.y == 0)
        cout << "Center\n";
    else if (p.x == 0)
        cout << "On X-axis\n";
    else if (p.y == 0)
        cout << "On Y-axis\n";
}

bool in_circle(const Point& p, int r) {
    if (p.x * p.x + p.y * p.y <= r * r)
        return true;
    return false;
}

int main() {
    Point a, b;
    write(a);
    read_point(a);
    distance_from_zero(a);
    write(b);
    distance_between_points(a, b);
    quadrant(a);
    cout << in_circle(a, 10);
}
