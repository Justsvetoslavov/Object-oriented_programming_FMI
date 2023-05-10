#pragma once
#include "../Computer.h"
#include "../../Device/Device.h"

class Laptop : Computer {
    Device mousePad;
    Device keyboard;
    Device monitor;
public:

    Laptop() = default;

    Laptop(const char* mousePad, const char* keyboard, const char* monitor);

    const Device &getMousePad() const;

    const Device &getKeyboard() const;

    const Device &getMonitor() const;

    void setMousePad(const Device &mousePad);

    void setKeyboard(const Device &keyboard);

    void setMonitor(const Device &monitor);

    void GetType() const override;

    void GetDevices() const override;
};
