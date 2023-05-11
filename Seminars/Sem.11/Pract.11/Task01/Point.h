#pragma once

struct Point
{
    int x = 0;
    int y = 0;

    Point(int, int);
};

double calculateDistance(const Point &, const Point &);
