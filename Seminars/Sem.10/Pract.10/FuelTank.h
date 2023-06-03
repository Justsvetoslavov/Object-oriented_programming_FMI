#pragma once
#include <iostream>
#include "insufficient_fuel_error.h"

const char _ERROR_MESSAGE[] = "Invalid data!";

MyString ERROR = "ERROR";

class FuelTank
{
    double capacity = 0;
    double filledFuel = 0;

public:

    FuelTank();

    const double getCapacity() const;

    const double getFilledFuel() const;

    void setCapacity(const double capacity);

    void setFilledFuel(const double filledFuel);

    FuelTank(const double capacity);

    void use(const double toUse);

    void fill(const double toFill);
};
