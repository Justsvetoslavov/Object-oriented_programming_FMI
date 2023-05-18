
#include "FuelTank.h"
#include <cmath>
#include "FuelError.h"

FuelTank::FuelTank(double cap, unsigned int indetificator,
                   const char *proizvoditel, const char *description) : CarPart(indetificator, proizvoditel,
                                                                                description) {
    setCapacity(cap);
    setFuel(cap);
}

void FuelTank::setCapacity(double cap) {
    capacity = cap;
}

void FuelTank::setFuel(double fuel) {
    double _fuel = std::min(capacity, std::max((double) 0, fuel));
    if(_fuel!=fuel){
        throw new FuelError("Error");
    }
    this->fuel = _fuel
}

void FuelTank::fill(double toFill) {
    setFuel(fuel + toFill);
}

void FuelTank::use(double toUse) {
    setFuel(fuel - toUse);
}

double FuelTank::getFuel() const {
    return this->fuel;
}
