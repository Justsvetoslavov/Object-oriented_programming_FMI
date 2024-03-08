#pragma once
#include "Computer.h"

class GamingConsole : public Computer
{
public:
	GamingConsole() = default;
	GamingConsole(double cpuPower, const String& gpuModel, int supplyPower, int ramSize);

	void printType() const override;
};

