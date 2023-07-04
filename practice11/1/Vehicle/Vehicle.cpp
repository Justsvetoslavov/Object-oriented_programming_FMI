#include "Vehicle.h"

void Vehicle::copyFrom(const Vehicle &vehicle) {
    countTires = vehicle.countTires;
    countPassengers = vehicle.countPassengers;
    averageSpeed = vehicle.averageSpeed;
    type = vehicle.type;
    tires = new Tires[countTires];
    for (int i = 0; i < countTires; ++i)
        tires[i] = vehicle.tires[i];
}

void Vehicle::free() {
    delete[] tires;
    type = EngineType::none;
    countPassengers = countTires = averageSpeed = 0;
}

Vehicle::~Vehicle() {
    free();
}

Vehicle &Vehicle::operator=(const Vehicle &vehicle) {
    if (this != &vehicle) {
        free();
        copyFrom(vehicle);
    }
    return *this;
}

Vehicle::Vehicle(const Vehicle &vehicle) {
    copyFrom(vehicle);
}

Vehicle::Vehicle() {
    type = EngineType::none;
    countPassengers = countTires = averageSpeed = 0;
    tires = nullptr;
}

Vehicle::Vehicle(const Tires *_tires, unsigned int countT, const EngineType &_type, unsigned int countP,
                 double averageS) : countTires(countT), countPassengers(countP), averageSpeed(averageS), type(_type) {
    tires = new Tires[countTires];
    for (int i = 0; i < countTires; ++i)
        tires[i] = _tires[i];
}

Vehicle::Point::Point(int x, int y) : x(x), y(y) {}

double Vehicle::findTime(const Point &a, const Point &b) const {
    return a.getDist(b);
}

double Vehicle::Point::getDist(const Point &a) const {
    return sqrt(pow(x - a.x, 2) + pow(y - a.y, 2));
}

void Vehicle::changeTire(const Tires &tire, unsigned int index) {
    if (index >= countTires)
        throw std::out_of_range("Out of bounds");
    tires[index] = tire;
}