#include "PC.h"

const Device &PC::getMouse() const {
    return mouse;
}

const Device &PC::getKeyboard() const {
    return keyboard;
}

const Device &PC::getMicrophone() const {
    return microphone;
}

const Device &PC::getHeadphone() const {
    return headphone;
}

void PC::setMouse(const Device &mouse) {
    PC::mouse = mouse;
}

void PC::setKeyboard(const Device &keyboard) {
    PC::keyboard = keyboard;
}

void PC::setMicrophone(const Device &microphone) {
    PC::microphone = microphone;
}

void PC::setHeadphone(const Device &headphone) {
    PC::headphone = headphone;
}

PC::PC(double power, const char *model, int consumption, int ram, const char *mouse, const char *keyboard,
       const char *microphone, const char *headphone) : Computer(power, model, consumption, ram) {
    this->mouse.setModel(mouse);
    this->keyboard.setModel(keyboard);
    this->microphone.setModel(microphone);
    this->headphone.setModel(headphone);
}

void PC::GetType() const {
    std::cout << "It's PC\n";
    getInfo();
}

void PC::GetDevices() const {
    std::cout << "Mouse: " << mouse.getModel()
              << "\nKeyboard: " << keyboard.getModel()
              << "\nMicrophone: " << microphone.getModel()
              << "\nHeadphone: " << headphone.getModel() << std::endl;
}