#pragma once
#include "../CarPart/Battery/Battery.h"
#include "../CarPart/Engine/Engine.h"
#include "../CarPart/Reservoir/Reservoir.h"
#include "../CarPart/Tires/Tires.h"

class Car {
    Reservoir reservoir;
    Engine engine;
    Tires tires[4];
    Battery battery;
    double mileage;
    double weight;

public:
    Car(const Reservoir& reservoir, const Engine& engine, const Tires *tires,
        const Battery& battery, double mileage, double weight);
    const Reservoir& getReservoir() const;
    void drive(double km);
    friend Car* dragRace(Car* car1, Car* car2);
    unsigned int getHorsePower() const;
};