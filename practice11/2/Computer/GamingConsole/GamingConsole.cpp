//
// Created by grade on 5/10/2023.
//

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

GamingConsole::GamingConsole(const char *joystick, const char *display) {
    gamepad.setModel(joystick);
    monitor.setModel(display);
}

void GamingConsole::GetType() const {
    std::cout << "It's Gaming Console\n";
}

void GamingConsole::GetDevices() const {
    std::cout << "Gamepad: " << gamepad.getModel()
              << "\nMonitor: " << monitor.getModel() << std::endl;
}