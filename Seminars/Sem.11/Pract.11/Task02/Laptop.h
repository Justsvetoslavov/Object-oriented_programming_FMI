#pragma once

#include "Computer.h"

class Laptop : public Computer {
	MyString _mousePad;
	MyString _keyboard;
	MyString _monitor;
public:
	Laptop() = default;
	Laptop(double CPU_power, const MyString& videoCardModel, int powerSupply, int RAM,
	const MyString& mousePad, const MyString& keyboard, const MyString& monitor);

	void printComputerType() const override;
	const MyString& getPeripheralDevices() const override;
};