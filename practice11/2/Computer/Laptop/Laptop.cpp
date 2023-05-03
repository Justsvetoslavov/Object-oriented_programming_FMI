
#include "Laptop.h"

const Device &Laptop::getMousePad() const {
    return mousePad;
}

const Device &Laptop::getKeyboard() const {
    return keyboard;
}

const Device &Laptop::getMonitor() const {
    return monitor;
}

void Laptop::setMousePad(const Device &mousePad) {
    Laptop::mousePad = mousePad;
}

void Laptop::setKeyboard(const Device &keyboard) {
    Laptop::keyboard = keyboard;
}

void Laptop::setMonitor(const Device &monitor) {
    Laptop::monitor = monitor;
}

Laptop::Laptop(double power, const char* model, int consumption, int ram,
               const char *mousePad, const char *keyboard, const char *monitor) : Computer(power, model, consumption, ram) {
    this->mousePad.setModel(mousePad);
    this->keyboard.setModel(keyboard);
    this->monitor.setModel(monitor);
}

void Laptop::GetType() const {
    std::cout << "It's laptop\n";
    getInfo();
}

void Laptop::GetDevices() const {
    std::cout << "Mousepad: " << mousePad.getModel()
              << "\nKeyboard: " << keyboard.getModel()
              << "\nMonitor: " << monitor.getModel() << std::endl;
}