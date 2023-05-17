#pragma once

#include "Computer.h"

class PC : public Computer{
private:
	MyString _mouse;
	MyString _keyboard;
	MyString _microphone;
	MyString _headphones;

public:
	PC() = default;
	PC(double CPU_power, const MyString& videoCardModel, int powerSupply, int RAM,
	const MyString& mouse, const MyString& keyboard, const MyString& microphone, const MyString& headphones);

	void printComputerType() const override;
	const MyString& getPeripheralDevices() const override;
};