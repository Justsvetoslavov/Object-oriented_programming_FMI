#pragma once
#include "Computer.h"

class GamingConsole : public Computer
{
public:
	static const size_t peripheryCount = 2;
	constexpr static const char* periphery[peripheryCount] = { "Joystick", "Display"};

	const char* const* getPeripheryDevices() const override;
	void printType() const override;
};

