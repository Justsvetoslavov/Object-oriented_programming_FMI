#pragma once
#include "Computer.h"

class Laptop : Computer
{
public:
    Laptop(double, const char *, int, int);
    void computerType() const override final;
    void availablePeripherals() const override final;
};