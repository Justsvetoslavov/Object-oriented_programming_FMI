#include "PC.h"
#include <iostream>

PC::PC(double processorPower, const char *videoCardSerialNum, int powerSupply, int RAM) : Computer(processorPower, videoCardSerialNum, powerSupply, RAM)
{
}

void PC::computerType() const
{
    std::cout << "This is PC.\n";
}

void PC::availablePeripherals() const
{
    std::cout << "Available peripherals: mouse, keyboard, microphone, headphones.\n";
}
