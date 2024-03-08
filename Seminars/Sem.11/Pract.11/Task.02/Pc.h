#pragma once
#include "Computer.h"

class Pc : public Computer
{
public:
	Pc() = default;
	Pc(double cpuPower,
		const String& gpuModel,
		int supplyPower,
		int ramSize);

	void printType() const override;
};

