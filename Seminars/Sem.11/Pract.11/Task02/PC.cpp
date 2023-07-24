#include "PC.h"

#include <iostream>

const char* const* PC::getPeripheryDevices() const
{
	return PC::periphery;
}

void PC::printType() const
{
	std::cout << "PC";
}
