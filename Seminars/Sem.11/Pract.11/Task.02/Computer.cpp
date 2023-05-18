#include "Computer.h"

Computer::Computer(
	double cpuPower,
	const String& gpuModel,
	int supplyPower,
	int ramSize)
	: cpuPower(cpuPower),
	gpuModel(gpuModel),
	supplyPower(supplyPower),
	ramSize(ramSize)
{
}

double Computer::getCpuPower() const
{
	return cpuPower;
}

void Computer::setCpuPower(double data)
{
	if (data <= 0)
		return;

	cpuPower = data;
}

const String& Computer::getGpuModel() const
{
	return gpuModel;
}

void Computer::setGpuModel(const String& data)
{
	if (data == "")
		return;

	gpuModel = data;
}

int Computer::getSupplyPower() const
{
	return supplyPower;
}

void Computer::setSupplyPower(int data)
{
	if (data <= 0)
		return;

	supplyPower = data;
}

int Computer::getRamSize() const
{
	return ramSize;
}

void Computer::setRamSize(int data)
{
	if (data <= 0)
		return;

	ramSize = data;
}
