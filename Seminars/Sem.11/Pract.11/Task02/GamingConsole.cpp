#include "GamingConsole.h"
#include <iostream>

GamingConsole::GamingConsole(double processorPower, const char *videoCardSerialNum, int powerSupply, int RAM) : Computer(processorPower, videoCardSerialNum, powerSupply, RAM)
{
}

void GamingConsole::computerType() const
{
    std::cout << "This is Gaming Console.\n";
}

void GamingConsole::availablePeripherals() const
{
    std::cout << "Available peripherals: joystick, monitor.\n";
}