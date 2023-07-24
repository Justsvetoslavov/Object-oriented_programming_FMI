#include "GamingConsole.h"

#include <iostream>

const char* const* GamingConsole::getPeripheryDevices() const
{
	return GamingConsole::periphery;
}

void GamingConsole::printType() const
{
	std::cout << "Gaming console";
}
