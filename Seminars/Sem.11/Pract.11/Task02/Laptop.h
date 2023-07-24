#pragma once
#include "Computer.h"

class Laptop : public Computer
{
	static const size_t peripheryCount = 3;
	constexpr static const char* periphery[peripheryCount] = { "Mouse pad", "Keyboard", "Display"};

	const char* const* getPeripheryDevices() const override;
	void printType() const override;
};

