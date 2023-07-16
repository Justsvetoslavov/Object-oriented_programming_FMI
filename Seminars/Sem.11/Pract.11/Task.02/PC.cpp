#include "PC.h"
#include <cstring>
#include <iostream>

void PC::setPeripheralDevices()
{
	count = peripheral_devices_count;

	initializePeripheralDevices();

	strcpy((peripheralDevices[0]), "mouse");
	strcpy((peripheralDevices[1]), "keyboard");
	strcpy((peripheralDevices[2]), "microphone");
	strcpy((peripheralDevices[3]), "headphones");
}

void PC::writeComputerType() const
{
	std::cout << "Computer type -> PC" << std::endl;
}