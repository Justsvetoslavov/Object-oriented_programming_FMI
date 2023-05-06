#include "FuelTank.h"

FuelTank::FuelTank() = default;

const double FuelTank::getCapacity() const
{
    return capacity;
}

const double FuelTank::getFilledFuel() const
{
    return filledFuel;
}

void FuelTank::setCapacity(const double capacity)
{
    if (capacity <= 0)
    {
        std::cout << _ERROR_MESSAGE;
        return;
    }
    else
    {
        this->capacity = capacity;
    }
}

void FuelTank::setFilledFuel(const double filledFuel)
{
    if (filledFuel <= 0)
    {
        std::cout << _ERROR_MESSAGE;
        return;
    }
    else
    {
        this->filledFuel = filledFuel;
    }
}

FuelTank::FuelTank(const double capacity)
{
    this->capacity = capacity;
    this->filledFuel = this->capacity;
}

void FuelTank::use(const double toUse)
{
    if (filledFuel < toUse)
    {
        throw insufficient_fuel_error(ERROR);
    }
    else
    {
        filledFuel -= toUse;
    }
}

void FuelTank::fill(const double toFill)
{
    if (toFill > filledFuel)
    {
        filledFuel = capacity;
    }
    else
    {
        filledFuel += toFill;
    }
}