#pragma once
#include "MyString/MyString.h"
#include "Controls/Control.h"
#include "Collection/ControlContainer.h"

class Form
{
	struct Size
	{
		size_t _width = 0;
		size_t _height = 0;
	};

	MyString _name;
	Size _size = {0, 0};
	ControlContainer _controls;

public:
	Form(size_t, size_t, const MyString &);
	Form(size_t, size_t, const char *);

	void appendControl(ControlType);
	void appendControl(Control &);
	void appendControl(Control &&);

	void changeSize(size_t, size_t);
	const Control &getControl(size_t) const;
	Control &getControl(size_t);

	void popControl();
};
