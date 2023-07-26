#pragma once

#include "CarPart.h"

class FuelTank : public CarPart {
    const double capacity;
    double fuel;

public:
    explicit FuelTank(double capacity);

    double getCapacity() const;

    double getFuel() const;

    void use(double amount);

    void fill(double amount);
};