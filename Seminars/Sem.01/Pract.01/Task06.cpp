// Bozhidar, Group 1, practicum date 22.02.2023

#include <iostream>
#include <cmath>

struct Point
{
    double x = 0;
    double y = 0;
};

Point initPoint()
{
    Point newPoint;

    std::cout << "x: ";

    std::cin >> newPoint.x;

    std::cin.ignore();

    std::cout << "y: ";

    std::cin >> newPoint.y;

    return newPoint;
}

void printPoint(const Point &p)
{
    std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;
}

double getDistFromCenter(const Point &p)
{
    return sqrt(p.x * p.x + p.y * p.y);
}

double getDistBetweenPoints(const Point &a, const Point &b)
{
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

unsigned short getQuadrant(const Point &p)
{
    if (p.x > 0 && p.y > 0)
    {
        return 1;
    }

    if (p.x < 0 && p.y > 0)
    {
        return 2;
    }

    if (p.x < 0 && p.y < 0)
    {
        return 3;
    }

    if (p.x > 0 && p.y < 0)
    {
        return 4;
    }

    return 0;
}

void isPointInCircle(const int radius, const Point &point, const double EPSILON)
{
    double distFromCenter = getDistFromCenter(point);

    if (abs(distFromCenter - radius) < EPSILON)
    {
        std::cout << "Point lies on the circle";
        return;
    }

    if (distFromCenter > radius)
    {
        std::cout << "Point lies outside the circle";
        return;
    }

    if (distFromCenter < radius)
    {
        std::cout << "Point lies inside the circle";
        return;
    }
}

int main()
{
    const double EPSILON = 0.0001;

    Point point = initPoint();
    printPoint(point);

    isPointInCircle(5, point, EPSILON);

    return 0;
}
