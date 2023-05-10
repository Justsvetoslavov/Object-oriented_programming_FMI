#pragma once
#include "Computer.h"

const size_t peripheral_devices_count = 3;

class Laptop : public Computer
{
public:
	void setPeripheralDevices() override;
	void writeComputerType() const override;


};

