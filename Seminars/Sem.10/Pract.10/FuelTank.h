#pragma once

#include "CarPart.h"
#include <ostream>

class FuelTank : private CarPart {
private:
    double capacity;
    double fuel;
public:
    FuelTank() = default;

    FuelTank(double, unsigned, const char *, const char *);

    void fill(double);

    void use(double);

    double getFuel() const;

private:
    void setCapacity(double);

    void setFuel(double);
};


