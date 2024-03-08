#pragma once
#include "Computer.h"

class Laptop : public Computer
{
public:
	Laptop() = default;
	Laptop(double cpuPower, const String& gpuModel, int supplyPower, int ramSize);

	void printType() const override;
};

