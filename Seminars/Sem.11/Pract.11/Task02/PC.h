#pragma once
#include "Computer.h"

class PC : Computer
{
public:
    PC(double, const char *, int, int);
    void computerType() const override final;
    void availablePeripherals() const override final;
};