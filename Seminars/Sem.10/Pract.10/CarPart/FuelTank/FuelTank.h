#pragma once
#include <iostream>
#include "../Exceptions/insufficient_fuel_error.h"
class FuelTank{

    double capacity;
    double currentFuelAmount;

public:

    FuelTank(double capacity);

    void fill(double toFill);
    void use(double toUse);

    double getCurrentFuel() const;

};

