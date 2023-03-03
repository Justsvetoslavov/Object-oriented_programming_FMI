#include <iostream>
#include <cmath>

struct Point
{
    double x;
    double y;
};

void initializePoint(Point& point)
{
    std::cout << "Input point's coordinates\n";
    std::cout << "x: ";
    std::cin >> point.x;
    std::cout << "y: ";
    std::cin >> point.y;
}

void printPoint(const Point point)
{
    std::cout << "(" << point.x << ", " << point.y << ")" << std::endl;
}

double distanceFromCenter(const Point point)
{
    return sqrt(point.x * point.x + point.y * point.y);
}

double distanceBetweenPoints(const Point p1, const Point p2)
{
    return sqrt(abs(p1.x - p2.x) * abs(p1.x - p2.x) + abs(p1.y - p2.y) * abs(p1.y - p2.y));
}

int quadrant(const Point point)
{
    if (point.x == 0 && point.y == 0) return 0;
    if (point.x > 0 && point.y > 0) return 1;
    if (point.x < 0 && point.y > 0) return 2;
    if (point.x < 0 && point.y < 0) return 3;
    if (point.x > 0 && point.y < 0) return 4;
}

int main()
{
    Point point;
    initializePoint(point);

    std::cout << "Point: ";
    printPoint(point);

    std::cout << "Distance from the center of the coordinate system to the point: "
        << distanceFromCenter(point) << std::endl;

    Point point2;
    initializePoint(point2);
    std::cout << "Distance between the two points: "
        << distanceBetweenPoints(point, point2) << std::endl;

    std::cout << "The second point is in " << quadrant(point2) << " quadrant\n";

    return 0;
}