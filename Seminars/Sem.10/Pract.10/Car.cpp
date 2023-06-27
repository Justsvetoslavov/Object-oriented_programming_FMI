#include <iostream>
#include "Car.h"
#include "insufficient_fuel_exception.h"

Car::Car(Engine *engine,
         Tire *tires[4],
         CarBattery *carBattery,
         double fuelTankCapacity,
         double distanceTraveled,
         unsigned int weight) : _engine(engine), _carBattery(carBattery),
                                _fuelTank(fuelTankCapacity),
                                _distanceTraveled(distanceTraveled),
                                _weight(weight)
{
    for (unsigned short i = 0; i < 4; ++i)
        _tires[i] = tires[i];
}

const FuelTank &Car::getFuelTank() const
{
    return _fuelTank;
}

bool Car::drive(double km)
{
    try
    {
        _fuelTank.use(km);
    }
    catch (insufficient_fuel_exception &err)
    {
        std::cout << err.what() << '\n'
                  << "Unsuccessful drive.\n";
        return false;
    }
    catch (std::exception exc)
    {
        std::cout << "Exception occurred: " << exc.what() << '\n'
                  << "Unsuccessful drive.\n";
        return false;
    }
    catch (...)
    {
        std::cout << "Unknown error. Unsuccessful drive.\n";
        return false;
    }

    _distanceTraveled += km;
    return true;
}

Car *dragRace(Car *car1, Car *car2)
{
    static const double RACE_DISTANCE = 0.4;

    static bool sufficientFuelCar1 = car1->drive(RACE_DISTANCE);
    static bool sufficientFuelCar2 = car2->drive(RACE_DISTANCE);

    if (sufficientFuelCar1 && sufficientFuelCar2)
    {
        return (car1->_weight / car1->_engine->getHorsePowers() > car2->_weight / car2->_engine->getHorsePowers()) ? car1 : car2;
    }
    if (sufficientFuelCar1 && !sufficientFuelCar2)
    {
        return car1;
    }
    if (!sufficientFuelCar1 && sufficientFuelCar2)
    {
        return car2;
    }

    std::cout << "Unsuccessful race.\n";

    return nullptr;
}

std::ostream &operator<<(std::ostream &out, const Car &obj)
{
    return out << "Engine: " << *(obj._engine) << '\n'
               << "Tires: " << '\n'
               << '\t' << "Tire (1): " << *(obj._tires[0]) << '\n'
               << '\t' << "Tire (2): " << *(obj._tires[1]) << '\n'
               << '\t' << "Tire (3): " << *(obj._tires[2]) << '\n'
               << '\t' << "Tire (4): " << *(obj._tires[3]) << '\n'
               << "Car battery: " << *(obj._carBattery) << '\n'
               << "Weight: " << obj._weight << " kg." << '\n'
               << "Distance traveled: " << obj._distanceTraveled << " km." << '\n';
}
