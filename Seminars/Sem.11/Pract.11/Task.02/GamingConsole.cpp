#include "GamingConsole.h"

GamingConsole::GamingConsole(double cpuPower, const String& gpuModel, int supplyPower, int ramSize)
	: Computer(cpuPower, gpuModel, supplyPower, ramSize)
{
	peripherals[0] = "Controller";
	peripherals[1] = "Monitor";
	periphCount = 2;
}

void GamingConsole::printType() const
{
	std::cout << "Gaming Console";
}
