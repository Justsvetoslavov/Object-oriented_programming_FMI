#pragma once
#include "../Computer.h"
#include "../../Device/Device.h"

class Laptop : public Computer {
    Device mousePad;
    Device keyboard;
    Device monitor;
public:

    Laptop() = default;

    Laptop(double power, const char* model, int consumption, int ram,
            const char* mousePad, const char* keyboard, const char* monitor);

    const Device &getMousePad() const;

    const Device &getKeyboard() const;

    const Device &getMonitor() const;

    void setMousePad(const Device &mousePad);

    void setKeyboard(const Device &keyboard);

    void setMonitor(const Device &monitor);

    void GetType() const override;

    void GetDevices() const override;
};
