#include "Control.h"

Control::Control(ControlType type)
    : _type(type)
{
}

void Control::changeSize(size_t width, size_t height)
{
    _size._width = width;
    _size._height = height;
}

void Control::setIdxInForm(size_t idx)
{
    _idxInForm = idx;
}

const ControlType &Control::getType() const
{
    return _type;
}
