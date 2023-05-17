#pragma once

#include "MyString.h"

class Computer {
	double _CPU_power = 0;
	MyString _videoCardModel = "Unknown";
	int _powerSupply = 0;
	int _RAM = 0;

public:
	Computer() = default;
	Computer(double CPU_power, const MyString& videoCardModel, int powerSupply, int RAM);

	// Setters
	void setCPU_power(double CPU_power);
	void setVideoCardModel(const MyString& videoCardModel);
	void setPowerSupply(int powerSupply);
	void setRAM(int RAM);

	// Virtual functions 
	virtual const MyString& getPeripheralDevices() const = 0;
	virtual void printComputerType() const = 0;
	virtual ~Computer() = default;
};