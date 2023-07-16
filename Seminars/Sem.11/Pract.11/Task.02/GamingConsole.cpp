#include "GamingConsole.h"
#include <cstring>
#include <iostream>

void GamingConsole::setPeripheralDevices()
{
	count = peripheral_devices_count;

	initializePeripheralDevices();

	strcpy((peripheralDevices[0]), "joystick");
	strcpy((peripheralDevices[1]), "monitor");
}

void GamingConsole::writeComputerType() const
{
	std::cout << "Computer type -> Gaming Console" << std::endl;
}