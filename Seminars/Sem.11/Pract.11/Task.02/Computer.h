#pragma once
#include "Utils/String.h"

namespace globals {
	const int MAX_PERIPHERALS_COUNT = 4;
}

class Computer
{
	double cpuPower;
	String gpuModel;
	int supplyPower;
	int ramSize;

protected:
	String peripherals[globals::MAX_PERIPHERALS_COUNT];
	size_t periphCount = 0;

public:
	Computer() = default;
	Computer(
		double cpuPower,
		const String& gpuModel,
		int supplyPower,
		int ramSize);

	double getCpuPower() const;
	void setCpuPower(double data);

	const String& getGpuModel() const;
	void setGpuModel(const String& data);

	int getSupplyPower() const;
	void setSupplyPower(int data);

	int getRamSize() const;
	void setRamSize(int data);

	virtual void printType() const = 0;
};

