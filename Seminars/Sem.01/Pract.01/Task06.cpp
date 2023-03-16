#include <iostream>
#include <cmath>

const double EPSILON = 0.0001;

struct Point
{
    double x = 0;
    double y = 0;
};

Point InitPoint(Point& point)
{
    std::cin >> point.x >> point.y;
}

void PrintPoint(const Point& point)
{
    std::cout << "(" << point.x << ", " << point.y << ")" << std::endl;
}

double GetDistFromCenter(const Point& point)
{
    return sqrt(point.x * point.x + point.y * point.y);
}

double GetDistBetweenPoints(const Point &f, const Point &s)
{
    //   ______________________________________________
    // \/ (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)
    // https://en.wikipedia.org/wiki/Euclidean_distance
    double dx = f.x - s.x;
    double dy = f.y - s.y;
    return sqrt(dx * dx + dy * dy);
}

unsigned short GetQuadrant(const Point& point)
{
    if (point.x > 0 && point.y > 0) {
        return 1;
    } else if (point.x < 0 && point.y > 0) {
        return 2;
    } else if (point.x < 0 && point.y < 0) {
        return 3;
    } else if (point.x > 0 && point.y < 0) {
        return 4;
    }
    
    return 0;
}

bool IsPointInCircle(const double radius, const Point& point)
{
    bool pointIsInCircle = false;
    double distFromCenter = getDistFromCenter(point);

    if (abs(distFromCenter - radius) < EPSILON) {
        std::cout << "Point lies on the circle";
    } else {
        if (distFromCenter > radius) {
            std::cout << "Point lies outside the circle\n";
            pointIsInCircle = true;
        } else {
            std::cout << "Point lies inside the circle\n";
        }
    }

    return pointIsInCircle;
}

int main() {
    Point point;
    InitPoint(point);
    PrintPoint(point);

    IsPointInCircle(5, point);
}
