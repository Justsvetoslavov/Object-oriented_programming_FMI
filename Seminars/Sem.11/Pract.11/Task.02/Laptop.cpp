#include "Laptop.h"
#include <cstring>
#include <iostream>

void Laptop::setPeripheralDevices()
{
	count = peripheral_devices_count;

	initializePeripheralDevices();

	strcpy((peripheralDevices[0]), "mouse pad");
	strcpy((peripheralDevices[1]), "keyboard");
	strcpy((peripheralDevices[2]), "monitor");
}


void Laptop::writeComputerType() const
{
	std::cout << "Computer type -> Laptop" << std::endl;
}