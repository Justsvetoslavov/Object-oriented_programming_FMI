#pragma once
#include "../Vehicle.h"

class Car : public Vehicle {
public:
    Car(const Tires *_tires, unsigned countT, const EngineType &_type, unsigned countP, double averageS);
    void GetPermit() const override;
};