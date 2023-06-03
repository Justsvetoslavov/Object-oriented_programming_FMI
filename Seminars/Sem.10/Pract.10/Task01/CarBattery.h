#pragma once
#include "CarPart.h"

class CarBattery: public CarPart
{
public:
	unsigned capacityAh = 0;
	MyString batteryId;

	CarBattery();
	CarBattery(unsigned id, const char* manufacturer, const char* description,
		unsigned capacityAh, const char* batteryId);

	friend std::ostream& operator<<(std::ostream& ofs, const CarBattery& carBattery);
};

std::ostream& operator<<(std::ostream& ofs, const CarBattery& carBattery);

