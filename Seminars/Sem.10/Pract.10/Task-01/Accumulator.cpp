#include "Accumulator.h"
#include <utility>

Accumulator::Accumulator() : Accumulator(0, "a0") {}

Accumulator::Accumulator(double capacity, const char *batteryId)
        : capacity{capacity} {
    copy(this->batteryId, batteryId);
}

Accumulator::Accumulator(const Accumulator &other) : CarPart(other) {
    copyFrom(other);
}

Accumulator::Accumulator(Accumulator &&other) noexcept: CarPart(std::move(other)) {
    moveFrom(std::move(other));
}

Accumulator &Accumulator::operator=(const Accumulator &other) {
    if (this != &other) {
        CarPart::operator=(other);
        free();
        copyFrom(other);
    }
    return *this;
}

Accumulator &Accumulator::operator=(Accumulator &&other) noexcept {
    if (this != &other) {
        CarPart::operator=(std::move(other));
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Accumulator::~Accumulator() {
    free();
}

void Accumulator::free() {
    delete[] batteryId;
    batteryId = nullptr;
}

void Accumulator::copyFrom(const Accumulator &other) {
    capacity = other.capacity;
    copy(batteryId, other.batteryId);
}

void Accumulator::moveFrom(Accumulator &&other) {
    capacity = other.capacity;
    batteryId = other.batteryId;
    other.batteryId = nullptr;
}

double Accumulator::getCapacity() const {
    return capacity;
}

const char *Accumulator::getBatteryId() const {
    return batteryId;
}

void Accumulator::setCapacity(double capacity) {
    this->capacity = capacity;
}

void Accumulator::setBatteryId(const char *batteryId) {
    free();
    copy(this->batteryId, batteryId);
}

std::ostream &operator<<(std::ostream &os, const Accumulator &accumulator) {
    return os << (CarPart &) accumulator << accumulator.getCapacity() << " Ah";
}