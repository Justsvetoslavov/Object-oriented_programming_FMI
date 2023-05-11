#pragma once
#include "Computer.h"

class GamingConsole : Computer
{
public:
    GamingConsole(double, const char *, int, int);
    void computerType() const override final;
    void availablePeripherals() const override final;
};