#include "Control.h"

//void Control::changeLocation(const Form* formPtr, const Point& newLocation)
//{
//	/**
//	 * Incl validation https://github.com/Angeld55/Object-oriented_programming_FMI/blob/master/Week%2012/Polymorphic%20containters/ShapeCollection/Rectangle.cpp
//	 *
//	 * Injected formPtr for check
//	 */
//
//	this->upperLeft = newLocation;
//}

void Control::changeLocation(const Point& newLocation)
{
	this->upperLeft = newLocation;
}