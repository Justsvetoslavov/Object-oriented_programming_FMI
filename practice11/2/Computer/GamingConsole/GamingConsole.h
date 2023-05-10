#pragma once
#include "../Computer.h"
#include "../../Device/Device.h"


class GamingConsole : public Computer {
    Device gamepad;
    Device monitor;
public:
    GamingConsole() = default;

    GamingConsole(double power, const char* model, int consumption, int ram, const char* joystick, const char* display);

    const Device &getGamepad() const;

    const Device &getMonitor() const;

    void setGamepad(const Device &gamepad);

    void setMonitor(const Device &monitor);

    void GetType() const override;

    void GetDevices() const override;
};
