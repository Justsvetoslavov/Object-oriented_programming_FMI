#include "Laptop.h"
#include <iostream>

Laptop::Laptop(double processorPower, const char *videoCardSerialNum, int powerSupply, int RAM) : Computer(processorPower, videoCardSerialNum, powerSupply, RAM)
{
}

void Laptop::computerType() const
{
    std::cout << "This is Laptop.\n";
}

void Laptop::availablePeripherals() const
{
    std::cout << "Available peripherals: mouse pad, keyboard, monitor.\n";
}
