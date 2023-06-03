#pragma once

#include "FuelTank.h"
#include "Engine.h"
#include "Accumulator.h"
#include "Tire.h"

class Car {
private:
    FuelTank tank;
    Engine engine;
    Tire tires[4];
    Accumulator accumulator;
    double kilometers = 0;
    double mass = 0;
public:
    Car() = delete;

    Car(const FuelTank &&, const Engine &&, const Tire *, const Accumulator &&, double, double);

    const FuelTank &getFuelTank();

    const Engine &getEngine();

    void drive(double);

    double getMass() const;
};

Car *dragRace(Car *car1, Car *car2);