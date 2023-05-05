#include "Car.h"
#include <iostream>

Car::Car(double tankCapacity, const Engines& engines, const Tires& tire, const Accumulators& accumulator, double km, double weight)
    : reservoir(tankCapacity), engine(engines), accumulator(accumulator), km(km), weight(weight)
{
    for (int i = 0; i <= num_of_tires; i++) 
    {
        tires[i] = tire;
    }
};

const FuelTank& Car::getFuelTank()const 
{
	return  reservoir;
}

double Car::getkm()const 
{
    return km;
}

double Car::getWeight()const 
{
    return weight;
}

void  Car::drive(double km) 
{
    double fuelConsumption = km;
    if (fuelConsumption <= reservoir.getcurrentFuel()) {
        reservoir.useFuel(fuelConsumption);
        this->km = km;
    }
}

const Engines& Car::getEngine()const
{
    return engine;
}

Car* dragRace(Car* car1, Car* car2) 
{

    double fuelNeeded = distance * fuel_per_km;
    double fuelCar1 = car1->getFuelTank().getcurrentFuel();
    double fuelCar2 = car2->getFuelTank().getcurrentFuel();

    if (fuelCar1<fuelNeeded && fuelCar2>fuelNeeded)
    {
        return car2;
    }

    else if (fuelCar2<fuelNeeded && fuelCar1>fuelNeeded) 
    {
        return car1;
    }

    else if (fuelCar1 < fuelNeeded && fuelCar2 < fuelNeeded) 
    {
        return nullptr;
    }

    double ratio1 = car1->getWeight() / car1->getEngine().getHp();
    double ratio2 = car2->getWeight() / car2->getEngine().getHp();

    if (ratio1 > ratio2) 
    {
        return car1;
    }

    else if (ratio2 > ratio1) 
    {
        return car2;
    }

    else 
    {
        return nullptr;
    }

}