#include "GamingConsole.h"

const Device &GamingConsole::getGamepad() const {
    return gamepad;
}

const Device &GamingConsole::getMonitor() const {
    return monitor;
}

void GamingConsole::setGamepad(const Device &gamepad) {
    GamingConsole::gamepad = gamepad;
}

void GamingConsole::setMonitor(const Device &monitor) {
    GamingConsole::monitor = monitor;
}

GamingConsole::GamingConsole(double power, const char *model, int consumption, int ram
                             , const char *joystick, const char *display) : Computer(power, model, consumption, ram) {
    gamepad.setModel(joystick);
    monitor.setModel(display);
}

void GamingConsole::GetType() const {
    std::cout << "It's Gaming Console\n";
    getInfo();
}

void GamingConsole::GetDevices() const {
    std::cout << "Gamepad: " << gamepad.getModel()
              << "\nMonitor: " << monitor.getModel() << std::endl;
}