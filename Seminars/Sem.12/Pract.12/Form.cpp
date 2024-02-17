#include "Form.h"
#include <iostream>

Form::Form(size_t width, size_t height, const MyString &name)
{
    _size._width = width;
    _size._height = height;

    _name = name;
}
Form::Form(size_t width, size_t height, const char *name)
{
    _size._width = width;
    _size._height = height;

    _name = std::move(MyString(name));
}

void Form::changeSize(size_t width, size_t height)
{
    _size._width = width;
    _size._height = height;
}

void Form::appendControl(ControlType type)
{
    _controls.push_back(type);
}

void Form::appendControl(Control &control)
{
    _controls.push_back(control);
}

void Form::appendControl(Control &&control)
{
    _controls.push_back(std::move(control));
}

const Control &Form::getControl(size_t idx) const
{
    return _controls.at(idx);
}

Control &Form::getControl(size_t idx)
{
    return _controls.at(idx);
}

void Form::popControl()
{
    if (_controls.isEmpty())
        throw std::length_error("There are no controls in the form.");

    _controls.pop_back();
}
