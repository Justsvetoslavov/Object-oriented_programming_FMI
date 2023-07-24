#include "Laptop.h"

#include <iostream>

const char* const* Laptop::getPeripheryDevices() const
{
	return Laptop::periphery;
}

void Laptop::printType() const
{
	std::cout << "Laptop";
}
