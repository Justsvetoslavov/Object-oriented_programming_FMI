#pragma once
#include "Point.h"

enum class ControlType
{
	label,
	checkBox,
	radioButton
};

//class Form;

class Control
{
protected:
	size_t widthPx = 0;
	size_t heightPx = 0;
	Point upperLeft;


public:
	virtual void setDataDialog() = 0;
	virtual Control* clone() const = 0;

	void setWidth(size_t width);
	void setHeight(size_t height);
	//void changeLocation(const Form* formPtr, const Point& newLocation);
	void changeLocation(const Point& newLocation);

	virtual ~Control() = default;
};

