#pragma once
#include "Computer.h"

const size_t peripheral_devices_count = 2;

class GamingConsole : public Computer
{
public:
	void setPeripheralDevices() override;
	void writeComputerType() const override;
};

