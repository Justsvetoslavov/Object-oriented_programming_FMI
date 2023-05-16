#pragma once
#include "CarPart.h"

class Accumulator : public CarPart{
private:
	int capacity = 0;
	String batteryId;

public:
	Accumulator() = default;
	Accumulator(int id, const char* name, const char* details, int capacity, const char* batteryId);
	friend std::ostream& operator<<(std::ostream& os, const Accumulator& other);
};

std::ostream& operator<<(std::ostream& os, const Accumulator& other);
