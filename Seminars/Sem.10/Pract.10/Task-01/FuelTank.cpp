#include "FuelTank.h"
#include "insufficient_fuel_error.h"

FuelTank::FuelTank(double capacity)
        : capacity{capacity}, fuel{capacity} {}

double FuelTank::getCapacity() const {
    return capacity;
}

double FuelTank::getFuel() const {
    return fuel;
}

void FuelTank::use(double amount) {
    if (fuel < amount) {
        throw insufficient_fuel_error("not enough fuel!");
    }
    fuel -= amount;
}

void FuelTank::fill(double amount) {
    fuel = (fuel + amount < capacity) ?
           fuel + amount : capacity;
}