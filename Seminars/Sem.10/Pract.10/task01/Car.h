#ifndef PRACT010_CAR_H
#define PRACT010_CAR_H
#include "CarPart.h"
#include "Engine.h"
#include "FuelTank.h"
#include "Battery.h"
#include "Tyre.h"

class Car {
    FuelTank fuelTank;
    Engine engine;
    Tyre* tyres;
    Battery battery;

    double kilometers;
    double weight;

public:

    Car(unsigned ftID, const MyString& ftName, const MyString &ftDescription
         ,double ftCapacity,
        unsigned engineID, const MyString &engineName, const MyString &engineDescription, unsigned engineHp,
        unsigned batteryID, const MyString &batteryName, const MyString &batteryDescription,
        unsigned batterCapcity,unsigned batteryID1,
        double kiometers, double weigth
    );

    Car(Engine&& eng, FuelTank&& ft, Tyre* tyresArr, Battery&& btr);

    unsigned getHP()const;
    double getWeight()const;

    const FuelTank& getFuelTank()const;

    Car& drive(double km);
};

Car dragRace(  Car& car1,  Car&car2);
#endif //PRACT010_CAR_H
