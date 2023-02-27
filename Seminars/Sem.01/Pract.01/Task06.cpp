#include <iostream>
#include <cmath>

struct Point
{
    double x;
    double y;
};

void initPoint(Point& p);
void printPoint(const Point& p);
double distanceFromTheCenter(const Point& p);
double distanceBetweenTwoPoints(const Point& p1, const Point& p2);
void quadrant(const Point& p);

int main()
{
    Point p1, p2;
    initPoint(p1);
    initPoint(p2);
    std::cout << '\n';
    printPoint(p1);
    std::cout << '\n';
    printPoint(p2);
    std::cout << '\n';
    std::cout << distanceFromTheCenter(p1);
    std::cout << '\n';
    std::cout << distanceBetweenTwoPoints(p1, p2);
    std::cout << '\n';
    quadrant(p1);
    std::cout << '\n';
    quadrant(p2);
    return 0;
}

void initPoint(Point& p)
{
    std::cin >> p.x >> p.y;
}

void printPoint(const Point& p)
{
    std::cout << '(' << p.x << ", " << p.y << ')';
}

double distanceFromTheCenter(const Point& p)
{
    return sqrt(p.x * p.x + p.y * p.y);
}

double distanceBetweenTwoPoints(const Point& p1, const Point& p2)
{
    double x = p1.x - p2.x;
    double y = p1.y - p2.y;
    return sqrt(x * x + y * y);
}

void quadrant(const Point& p)
{
    if (p.x == 0 && p.y == 0)
        std::cout << "The point is the center";
    if (p.x >= 0 && p.y > 0)
        std::cout << "The point is in 1st quadrant";
    else if (p.x < 0 && p.y >= 0)
        std::cout << "The point is in 2nd quadrant";
    else if (p.x <= 0 && p.y < 0)
        std::cout << "The point is in 3rd quadrant";
    else
        std::cout << "The point is in 4th quadrant";
}