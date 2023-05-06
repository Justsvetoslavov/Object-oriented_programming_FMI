#include <stdexcept>
#include <cstring>
#include "CarBattery.h"

CarBattery::CarBattery(unsigned int ID, const char *manufacturer, const char *description, unsigned int capacity, const char *batteryID) : CarPart(ID, manufacturer, description)
{
	if (!batteryID)
		throw std::invalid_argument("Invalid input data. Nullptr provided.");

	_capacity = capacity;

	_batteryID = new char[strlen(batteryID) + 1];
	strcpy(_batteryID, batteryID);
}

CarBattery::CarBattery(const CarBattery &other) : CarPart(other)
{
	copyFrom(other);
}

CarBattery &CarBattery::operator=(const CarBattery &other)
{
	if (this != &other)
	{
		CarPart::operator=(other);

		free();
		copyFrom(other);
	}
	return *this;
}

void CarBattery::copyFrom(const CarBattery &other)
{
	_capacity = other._capacity;
	copyBatteryID(other._batteryID);
}

void CarBattery::copyBatteryID(const char *batteryID)
{
	if (!batteryID)
		throw std::invalid_argument("Invalid input data. Nullptr provided.");

	_batteryID = new char[strlen(batteryID + 1)];
	strcpy(_batteryID, batteryID);
}

void CarBattery::free()
{
	delete[] _batteryID;
	_batteryID = nullptr;
}

std::ostream &operator<<(std::ostream &out, const CarBattery &obj)
{
	return out << (const CarPart &)obj << " - "
			   << "Battery ID " << obj._batteryID << " - " << obj._capacity << " Ah";
}

CarBattery::~CarBattery()
{
	free();
}
