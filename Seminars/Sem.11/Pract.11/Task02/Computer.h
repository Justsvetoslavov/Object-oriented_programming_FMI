#pragma once

#include "MyString.h"

class Computer
{
	double clockRate = 0;
	char* gpuModel = nullptr;
	unsigned powerWattage = 0;
	unsigned ram = 0;

protected:
	Computer();
	Computer(double clockRate, const char* gpuModel, unsigned powerWattage, unsigned ram);

	void setClockRate(double clockRate);
	void setGpuModel(const char* gpuModel);
	void setPowerWattage(unsigned powerWattage);
	void setRam(unsigned ram);

	virtual void printType() const = 0;
	virtual const char* const* getPeripheryDevices() const = 0;

	virtual ~Computer();
};

