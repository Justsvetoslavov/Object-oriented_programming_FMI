#pragma once
#include "../Computer.h"
#include "../../Device/Device.h"

class PC : Computer{
    Device mouse;
    Device keyboard;
    Device microphone;
    Device headphone;

public:

    PC() = default;

    PC(const char* mouse, const char* keyboard, const char* microphone, const char* headphone);

    const Device &getMouse() const;

    const Device &getKeyboard() const;

    const Device &getMicrophone() const;

    const Device &getHeadphone() const;

    void setMouse(const Device &mouse);

    void setKeyboard(const Device &keyboard);

    void setMicrophone(const Device &microphone);

    void setHeadphone(const Device &headphone);

    void GetType() const override;

    void GetDevices() const override;
};

