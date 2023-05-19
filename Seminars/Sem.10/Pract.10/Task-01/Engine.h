#pragma once

#include "CarPart.h"

class Engine : public CarPart {
    short horsePower;
public:
    explicit Engine(short horsePower);

    double getHorsePower() const;

    void setHorsePower(short horsePower);
};

std::ostream &operator<<(std::ostream& os, const Engine& engine);