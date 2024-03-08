#include "Laptop.h"

Laptop::Laptop(double cpuPower, const String& gpuModel, int supplyPower, int ramSize)
	: Computer(cpuPower, gpuModel, supplyPower, ramSize)
{
	peripherals[0] = "Mouse pad";
	peripherals[1] = "Keyboard";
	peripherals[2] = "Monitor";

	periphCount = 3;
}

void Laptop::printType() const
{
	std::cout << "Laptop";
}
