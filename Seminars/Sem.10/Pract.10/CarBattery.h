#pragma once
#include <ostream>
#include "CarPart.h"

class CarBattery : CarPart
{
	char *_batteryID = nullptr;
	unsigned int _capacity = 0;

public:
	CarBattery(unsigned int, const char *, const char *,
			   unsigned int, const char *);
	CarBattery(const CarBattery &);
	CarBattery &operator=(const CarBattery &);
	~CarBattery();

	friend std::ostream &operator<<(std::ostream &, const CarBattery &);

private:
	void copyFrom(const CarBattery &);
	void copyBatteryID(const char *);
	void free();
};
