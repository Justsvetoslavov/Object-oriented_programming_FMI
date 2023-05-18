#include "Computer.h"
#include <exception>
#include <iostream>

Computer::Computer() : Computer(0, "Unknown", 0, 0)
{
}

Computer::Computer(const double clockRate, const char* gpuModel, const unsigned powerWattage, const unsigned ram)
{
	setClockRate(clockRate);
	try
	{
		setGpuModel(gpuModel);
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what();
	}
	setPowerWattage(powerWattage);
	setRam(ram);
}

void Computer::setClockRate(const double clockRate)
{
	this->clockRate = clockRate;
}

void Computer::setGpuModel(const char* gpuModel)
{
	if (gpuModel == nullptr)
	{
		throw std::exception("Gpu model is nullptr");
	}

	this->gpuModel = new char[strlen(gpuModel)]{};
	strcpy(this->gpuModel, gpuModel);
}

void Computer::setPowerWattage(const unsigned powerWattage)
{
	this->powerWattage = powerWattage;
}

void Computer::setRam(const unsigned ram)
{
	this->ram = ram;
}

Computer::~Computer()
{
	delete[] this->gpuModel;
}
