#include "Car.h"

Car::Car(FuelTank fuelTank,
    Engine *engine,
    Tire *tires[],
    CarBattery *battery,
    double kilometers,
    double weight,
    double fuelCapacity)
{
    for (int i = 0; i < TIRES; ++i)
    {
        this->tires[i] = tires[i];
    }
}

const FuelTank &Car::getFuelTank() const
{
    return fuelTank;
}

void Car::drive(double kilometers)
{
    if (kilometers < fuelTank.getFilledFuel())
    {
        this->kilometers += kilometers;

        double currentFuelLiters = fuelTank.getFilledFuel();
        fuelTank.setFilledFuel(currentFuelLiters + kilometers);
    }
}