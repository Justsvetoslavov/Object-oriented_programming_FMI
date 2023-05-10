#include "Computer.h"
#include <cstring>

void Computer::initializePeripheralDevices()
{
	peripheralDevices = new char* [count];
	for (size_t i = 0; i < count; ++i)
	{
		peripheralDevices[i] = new char[MAX_SIZE_DEVICE];
	}
}

void Computer::changeType(const char* newTypeVideoCard)
{
	delete[] typeVideoCard;

	typeVideoCard = new char[strlen(newTypeVideoCard) + 1];
	strcpy(typeVideoCard, newTypeVideoCard);
}

void Computer::changePowerSupply(const int newPowerSupply)
{
	powerSupply = newPowerSupply;
}

void Computer::changeRam(const int newRam)
{
	ram = newRam;
}

void Computer::changeProcessorPower(const double newProcessorPower)
{
	processorPower = newProcessorPower;
}

const char** Computer::getPeripheralDevices() const
{
	return peripheralDevices;
}

Computer::~Computer()
{
	for (size_t i = 0; i < count; ++i)
	{
		delete[] peripheralDevices[i];
	}

	delete[] peripheralDevices;

	delete[] typeVideoCard;
}