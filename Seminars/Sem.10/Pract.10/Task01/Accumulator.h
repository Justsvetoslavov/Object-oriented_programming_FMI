#pragma once
#include "CarPart.h"
class Accumulator : public CarPart
{
private:
	unsigned capacity = 0;
	MyString batteryId;
public:
	Accumulator() = default;
	Accumulator(unsigned id, const MyString& manufacturerName, const MyString& descripiton,
				unsigned capacity, const MyString& batteryId);

	void SetCapacity(unsigned capacity);

	friend std::ostream& operator<<(std::ostream& os, const Accumulator& accumulator);
};

