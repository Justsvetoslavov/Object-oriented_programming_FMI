#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int deg(int num, int deg) {
    int res = 1;
    for (size_t i = 0; i < deg; i++)
        res *= num;
    return res;
}

struct Point {
    int x, y;
};

void read_point(const Point &p) {
    cout << "X: " << p.x << endl
         << "Y: " << p.y << endl;
}

void write(Point& p) {
    int x, y;
    cin >> x >> y;
    p.x = x;
    p.y = y;
}

void distance_from_zero(const Point& p) {
    cout << sqrt(deg(p.x, 2) + deg(p.y, 2)) << endl;
}

void distance_between_points(const Point& a, const Point& b) {
    cout << sqrt(deg(a.x - b.x, 2) + deg(a.y - b.y, 2)) << endl;
}

void kvadrant(const Point& p) {
    if (p.x > 0 && p.y > 0)
        cout << "I";
    else if (p.x < 0 && p.y > 0)
        cout << "II";
    else if (p.x < 0 && p.y < 0)
        cout << "III";
    else if (p.x > 0 && p.y < 0)
        cout << "IV";
    else if (p.x == 0 && p.y == 0)
        cout << "center";
}

bool in_circle(const Point& p, int r) {
    if (deg(p.x, 2) + deg(p.y, 2) <= deg(r, 2))
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
    kvadrant(a);
    cout << endl << in_circle(a, 10);
}