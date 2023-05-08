#include "FuelTank.h"

FuelTank::FuelTank(double _capacity){

    capacity = _capacity;
    currentFuelAmount = capacity;

}

void FuelTank::use(double toUse){

    if(toUse < 0)throw std::invalid_argument("toUse cannot be < 0");
    if(toUse > currentFuelAmount)throw insufficient_fuel_error("cannot use more fuel than currentAmount");
    currentFuelAmount -= toUse;

}
void FuelTank::fill(double toFill){

    if(toFill < 0)throw std::invalid_argument("toFill cannot be < 0");
    if(currentFuelAmount + toFill > capacity)
        currentFuelAmount = capacity;
    else currentFuelAmount +=toFill;


}

double FuelTank::getCurrentFuel() const {
    return currentFuelAmount;
}
