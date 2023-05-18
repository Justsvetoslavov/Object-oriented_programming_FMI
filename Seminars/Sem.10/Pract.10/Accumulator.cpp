
#include "Accumulator.h"
#include <cstring>

Accumulator::Accumulator(unsigned int cap, const char *id, unsigned int indetificator,
                         const char *proizvoditel, const char *description) : CarPart(indetificator, proizvoditel,
                                                                                      description) {
    setCapacity(cap);
    setBatteryId(id);
}

Accumulator::Accumulator(const Accumulator &other) : CarPart(other) {
    copyFrom(other);
}

Accumulator &Accumulator::operator=(const Accumulator &other) {
    if (this != &other) {
        CarPart::operator=(other);
        free();
        copyFrom(other);
    }

    return *this;
}

Accumulator::~Accumulator() {
    free();
}

void Accumulator::free() {
    delete batteryId;
    batteryId = nullptr;
}

void Accumulator::copyFrom(const Accumulator &other) {
    setCapacity(other.capacity);
    setBatteryId(other.batteryId);

}

void Accumulator::setCapacity(unsigned int cap) {
    capacity = cap;

}

void Accumulator::setBatteryId(const char *id) {
    batteryId = new char[strlen(id)];
    strcpy(batteryId, id);
}

std::ostream &operator<<(std::ostream &os, const Accumulator &accumulator) {
    os << (CarPart &) accumulator << " - " << accumulator.capacity << " Ah";
    return os;
}


