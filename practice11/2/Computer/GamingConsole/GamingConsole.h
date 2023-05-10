#pragma once
#include "../Computer.h"
#include "../../Device/Device.h"


class GamingConsole : Computer {
    Device gamepad;
    Device monitor;
public:
    GamingConsole() = default;

    GamingConsole(const char* joystick, const char* display);

    const Device &getGamepad() const;

    const Device &getMonitor() const;

    void setGamepad(const Device &gamepad);

    void setMonitor(const Device &monitor);

    void GetType() const override;

    void GetDevices() const override;
};
