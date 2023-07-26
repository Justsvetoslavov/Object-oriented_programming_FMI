#pragma once
#include "ControlContainer.h"

class Form
{
	size_t widthPx = 0;
	size_t heightPx = 0;
	Point upperLeft;

public:
	ControlContainer controls;

	Form() = default;
	Form(size_t widthPx, size_t heightPx, const Point& upperLeft);

	void setWidth(size_t width);
	void setHeight(size_t height);

	/*friend void Control::changeLocation(const Form* formPtr, const Point& newLocation);*/
};

