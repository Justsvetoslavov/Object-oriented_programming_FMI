#include "Point.h"
#include <math.h>

Point::Point(int x, int y) : x(x), y(y)
{
}

double calculateDistance(const Point &A, const Point &B)
{
    return sqrt((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
}