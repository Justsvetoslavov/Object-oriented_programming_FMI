#include "Battery.h"

Battery::Battery(unsigned int id, const MyString &name, const MyString &description, unsigned int capacity,
                 unsigned int BatteryId):CarPart(id,name,description) {
    setCapacity(capacity);
    setBatteryId(BatteryId);
}
unsigned int Battery::getCapacity() const {
    return capacity;
}

void Battery::setCapacity(unsigned int capacity) {
    Battery::capacity = capacity;
}

unsigned int Battery::getBatteryId() const {
    return batteryId;
}

void Battery::setBatteryId(unsigned int id) {
    Battery::batteryId = id;
}

std::ostream & operator<<(std::ostream&os, const Battery& bt){
    os<<(CarPart&)bt<<"- ";
    os<<bt.capacity<<" Ah ";
    return os;

}


