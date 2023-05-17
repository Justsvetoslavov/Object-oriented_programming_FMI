#pragma once

#include "Computer.h"

class GamingConsole : public Computer {
	MyString _joystick;
	MyString _monitor;

public:
	GamingConsole() = default;
	GamingConsole(double CPU_power, const MyString& videoCardModel, int powerSupply, int RAM,
	const MyString& joystick, const MyString& monitor);

	void printComputerType() const override;
	const MyString& getPeripheralDevices() const override;
};