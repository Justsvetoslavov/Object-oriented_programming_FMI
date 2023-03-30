#include <iostream>
#include "Point.h"

int main()
{
	Point p; //can't have default constructor and constructor with default parameters 
	Point p1(1, 2); //doesn't work because of delete Point(int, int)
	Point p = p1; // operator=
	Point p2(p); // copy constructor
	p2.SetY(2.3); //doesn't work because of delete setY(double double)
}