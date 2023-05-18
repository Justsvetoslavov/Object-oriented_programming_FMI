#pragma once
#include "Computer.h"

class PC : public Computer
{
public:
	static const size_t peripheryCount = 4;
	constexpr static const char* periphery[peripheryCount] = { "Mouse", "Keyboard", "Microphone", "Headphones" };

	const char* const* getPeripheryDevices() const override;
	void printType() const override;
};

