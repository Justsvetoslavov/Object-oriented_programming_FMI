#pragma once
#include "../CarPart.h"

class Reservoir : CarPart {
    double volume = 0;
    double petrol = 0;

public:
    Reservoir() = default;
    Reservoir(int id, const char* name, const char* desc, double volume);
    void use(double toUse);
    void fill(double toFill);
    double getPetrol() const;
};