#include <stdexcept>
#include "ControlContainer.h"
#include "../Factory/ControlFactory.h"

ControlContainer::ControlContainer()
{
    _controls = new Control *[_capacity];
}

ControlContainer::ControlContainer(const ControlContainer &other)
{
    copyFrom(other);
}

ControlContainer::ControlContainer(ControlContainer &&other) noexcept
{
    moveFrom(std::move(other));
}

ControlContainer &ControlContainer::operator=(const ControlContainer &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

ControlContainer &ControlContainer::operator=(ControlContainer &&other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

ControlContainer::~ControlContainer()
{
    free();
}

void ControlContainer::push_back(ControlType type)
{
    if (_size == _capacity)
        resize();

    _controls[_size++] = controlFactory(type);
}

void ControlContainer::push_back(Control &control)
{
    if (_size == _capacity)
        resize();

    _controls[_size++] = copyControlFactory(control);
}

void ControlContainer::push_back(Control &&control) noexcept
{
    if (_size == _capacity)
        resize();

    _controls[_size++] = moveControlFactory(std::move(control));
}

void ControlContainer::pop_back()
{
    if (isEmpty())
        throw std::length_error("Container is already empty.");

    --_size;
}

Control &ControlContainer::at(size_t idx)
{
    if (idx >= _size)
        throw std::range_error("Index out of range.");

    return *_controls[idx];
}

const Control &ControlContainer::at(size_t idx) const
{
    if (idx >= _size)
        throw std::range_error("Index out of range.");

    return *_controls[idx];
}

bool ControlContainer::isEmpty() const noexcept
{
    return !_size;
}

size_t ControlContainer::size() const noexcept
{
    return _size;
}

void ControlContainer::free()
{
    for (size_t i = 0; i < _size; ++i)
        delete _controls[i];

    delete[] _controls;
    _controls = nullptr;
}

void ControlContainer::copyFrom(const ControlContainer &other)
{
    _controls = new Control *[other._capacity];

    for (size_t i = 0; i < other._size; ++i)
        _controls[i] = other._controls[i]->clone();

    _size = other._size;
    _capacity = other._capacity;
}

void ControlContainer::moveFrom(ControlContainer &&other) noexcept
{
    _controls = other._controls;
    other._controls = nullptr;

    _size = other._size;
    other._size = 0;

    _capacity = other._capacity;
    other._capacity = 0;
}

void ControlContainer::resize()
{
    Control **newControls = new Control *[_capacity *= 2];

    for (size_t i = 0; i < _size; ++i)
        newControls[i] = _controls[i];

    delete[] _controls;
    _controls = newControls;
}
