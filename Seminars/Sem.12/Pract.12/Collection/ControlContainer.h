#pragma once
#include <cstddef>
#include "../Controls/Control.h"

const unsigned DEFAULT_CAPACITY_CONTAINER = 8;

class ControlContainer final
{
    Control **_controls = nullptr;
    size_t _size = 0;
    size_t _capacity = DEFAULT_CAPACITY_CONTAINER;

public:
    ControlContainer();
    ControlContainer(const ControlContainer &);
    ControlContainer(ControlContainer &&) noexcept;

    ControlContainer &operator=(const ControlContainer &);
    ControlContainer &operator=(ControlContainer &&) noexcept;

    ~ControlContainer();

    void push_back(ControlType);
    void push_back(Control &);
    void push_back(Control &&) noexcept;
    void pop_back();

    Control &at(size_t);
    const Control &at(size_t) const;

    bool isEmpty() const noexcept;
    size_t size() const noexcept;

private:
    void free();
    void copyFrom(const ControlContainer &);
    void moveFrom(ControlContainer &&) noexcept;
    void resize();
};