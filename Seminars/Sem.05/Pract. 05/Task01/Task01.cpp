#include <iostream>
#include "Point.h"

int main()
{
    Point p; // We cannot create a point like that because the default constructor here is the same as the one with default parameters
    Point p1(2, 5);
    p = p1; // Using the default operator=
    Point p2(p1); // Using the default copy constructor
    std::cout << p1.GetDistance(5, 3, 1);
    p2.SetX(1.5); // Won't work because we have forbidden setting x and y with double numbers
}
