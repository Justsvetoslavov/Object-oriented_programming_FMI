#pragma once

#include "Engine.h"
#include "FuelTank.h"
#include "Tire.h"
#include "Accumulator.h"

class Car {
    Engine *engine;
    Tire *tires[4];
    Accumulator *accumulator;
    FuelTank tank;
    double km;
    double weight;

public:
    Car(Engine *e, Tire *t, Accumulator *a, const FuelTank &ft, double weight);

    Car(Engine *e, Tire *t, Accumulator *a, double fuelTankCapacity, double weight);

    const FuelTank &getFuelTank() const;

    double weightHorsePower() const;

    void drive(double dist);
};

Car *dragRace(Car *car1, Car *car2);