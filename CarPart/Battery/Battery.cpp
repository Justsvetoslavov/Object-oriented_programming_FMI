#include "Battery.h"

void Battery::free() {
    delete[] batteryId;
    capacity = 0;
}

void Battery::copyFrom(const Battery &battery) {
    batteryId = new char[strlen(battery.batteryId) + 1];
    strcpy(batteryId, battery.batteryId);
    capacity = battery.capacity;
}

Battery::Battery(int id, const char *name, const char *description, int capacity, const char *batteryId) : CarPart(id, name, description) {
    if (capacity < 0)
        throw std::invalid_argument("Invalid capacity");
    this->capacity = capacity;
    this->batteryId = new char[strlen(batteryId) + 1];
    strcpy(this->batteryId, batteryId);
}

Battery &Battery::operator=(const Battery &battery) {
    if (this != &battery) {
        CarPart::operator=(battery);
        free();
        copyFrom(battery);
    }
    return *this;
}

Battery::Battery(const Battery &battery) : CarPart(battery) {
    copyFrom(battery);
}

Battery::~Battery() {
    free();
}

Battery::Battery() : CarPart() {
    batteryId = new char[1];
    batteryId[0] = '\0';
    capacity = 0;
}

std::ostream& operator<<(std::ostream& os, const Battery& battery) {
    os << (CarPart)battery << " - " << battery.capacity << " Ah";
    return os;
}