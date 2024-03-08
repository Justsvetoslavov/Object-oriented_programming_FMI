#include "Pc.h"

Pc::Pc(double cpuPower, const String& gpuModel, int supplyPower, int ramSize)
	: Computer(cpuPower, gpuModel, supplyPower, ramSize)
{
	peripherals[0] = "Mouse";
	peripherals[1] = "Keyboard";
	peripherals[2] = "Microphone";
	peripherals[3] = "Headphones";

	periphCount = 4;
}

void Pc::printType() const {
	std::cout << "PC";
}
