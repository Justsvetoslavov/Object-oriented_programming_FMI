//Gabriela Mladenova 
//SI
//Group 1
//3MI0600225
#include <iostream>

struct Point
{
    int x;
    int y;
};
void inputPoint(Point& point)
{
    std::cout << "Enter x: ";
    std::cin >> point.x;
    std::cout << "Enter y: ";
    std::cin >> point.y;
}
double distBetweenTwoPoints(const Point& point1, const Point& point2)
{
    int distX = point1.x - point2.x;
    int distY = point1.y - point2.y;
    return sqrt(distX * distX + distY * distY);
}
void quadrant(const Point& point)
{
    if (point.x > 0 && point.y > 0)
    {
        std::cout << "first quadrant.";
    }
    if (point.x < 0 && point.y > 0)
    {
        std::cout << "second quadrant.";
    }
    if (point.x < 0 && point.y < 0)
    {
        std::cout << "third quadrant.";
    }
    if (point.x > 0 && point.y < 0)
    {
        std::cout << "fourth quadrant.";
    }
}
void isThePointInTheCircle(const Point& point, const int distance, const int radius)
{
    if (distance < radius)
    {
        std::cout << "The point is inside the circle.";
    }
    if (distance > radius)
    {
        std::cout << "The point is outside the circle.";
    }
    if (distance == radius)
    {
        std::cout << "The point is on the border of the circle.";
    }
}
void printPoint(const Point& point)
{
    std::cout << "(" << point.x << " , " << point.y << ")";
}
int main()
{
    Point point1 = {};
    Point point2 = {};
    Point center = { 0, 0 };
    double radius;
    std::cout << "Coordinates for point1: " << std::endl;
    inputPoint(point1);
    std::cout << "Coordinates for point2: " << std::endl;
    inputPoint(point2);
    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    double distFromPoint1ToPoint2 = distBetweenTwoPoints(point1, point2);
    double distFromPoint1ToCenter = distBetweenTwoPoints(point1, center);
    double distFromPoint2ToCenter = distBetweenTwoPoints(point2, center);

    std::cout << "The distance betweet point1 and point2 is: " << distFromPoint1ToPoint2 << std::endl;
    std::cout << "The distance betweet point1 and the center is: " << distFromPoint1ToCenter << std::endl;
    std::cout << "The distance betweet point2 and the center is: " << distFromPoint2ToCenter << std::endl;

    printPoint(point1);
    std::cout << " is in ";
    quadrant(point1);
    std::cout << std::endl;
    printPoint(point2);
    std::cout << " is in ";
    quadrant(point2);
    std::cout << std::endl;

    std::cout << "First point: ";
    isThePointInTheCircle(point1, distFromPoint1ToCenter, radius);
    std::cout << std::endl;
    std::cout << "Second point: ";
    isThePointInTheCircle(point2, distFromPoint2ToCenter, radius);

    return 0;
}
