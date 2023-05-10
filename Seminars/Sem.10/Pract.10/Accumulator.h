#include "CarPart.h"
#pragma once
#include <iostream>

class Accumulator: protected CarPart
{
	unsigned capacity;
	char* batteryId;

public:
	Accumulator();
	Accumulator(unsigned, char*);
	Accumulator(const Accumulator&);
	Accumulator& operator=(const Accumulator&);
	~Accumulator();

	unsigned getCapacity() const;
	char* getBatteryId() const;

	void setCapacity(unsigned);
	void setBatteryId(char*);

	friend std::ostream& operator<<(std::ostream, const Accumulator&);

private:
	void copyFrom(const Accumulator&);
	void free();
};
