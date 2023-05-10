#include "CarBattery.h"

CarBattery::CarBattery(unsigned ID, MyString manufacturer, MyString description, ushort capacity, MyString batteryID) : CarPart(ID, manufacturer, description){
	setCapacity(capacity);
	setBatteryID(batteryID);
}

void CarBattery::setCapacity(ushort capacity) {
	_capacity = capacity;
}

ushort CarBattery::getCapacity() const {
	return _capacity;
}

void CarBattery::setBatteryID(MyString batteryID) {
	_batteryID = batteryID;
}

MyString CarBattery::getBatteryID() const {
	return _batteryID;
}

std::ostream& operator << (std::ostream& os, const CarBattery& c) {
	os << (CarPart)c;
	return os << "-" << c.getCapacity() << "Ah";
}