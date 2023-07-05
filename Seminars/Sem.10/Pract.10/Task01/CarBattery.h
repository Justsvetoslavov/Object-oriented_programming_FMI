#pragma once

#include "CarPart.h"

typedef unsigned short ushort;

class CarBattery : public CarPart {
	MyString _batteryID = "Unknown";
	ushort _capacity = 0;

public:
	CarBattery() = default;
	CarBattery(unsigned ID, MyString manufacturer, MyString description, ushort capacity, MyString batteryID);

	void setCapacity(ushort capacity);
	ushort getCapacity() const;

	void setBatteryID(MyString batteryID);
	MyString getBatteryID() const;
};

std::ostream& operator << (std::ostream& os, const CarBattery& c);