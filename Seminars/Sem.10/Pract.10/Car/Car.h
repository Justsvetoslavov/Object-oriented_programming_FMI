#pragma once
#include "../CarPart/CarPart.cpp"
#include "../CarPart/Tier/Tier.cpp"
#include "../CarPart/Battery/Battery.cpp"
#include "../CarPart/Engine/Engine.cpp"
#include "../CarPart/FuelTank/FuelTank.cpp"
#include "../TirePack/TirePack.cpp"
class Car{

    Engine engine;
    Battery battery;
    FuelTank fuelTank;
    TirePack tirePack;

    double weight;
    unsigned int mileage;

public:

    Car(const Engine& _engine,const Battery& _battery,const FuelTank& _fuelTank,const TirePack& _tirePack,
        double _weight,unsigned int _mileage);
    Car( Engine&& _engine, Battery&& _battery, FuelTank&& _fuelTank, TirePack&& _tirePack,
        double _weight,unsigned int _mileage);

    const FuelTank& getFuelTank() const;



    void drive(double km);

    const Engine& getEngine() const;
    const Battery& getBattery() const;
    const TirePack& getTirePack() const;
    double getWeight() const;
    unsigned int getMileage() const;

    void setEngine(const Engine &engine);

    void setBattery(const Battery &battery);

    void setFuelTank(const FuelTank &fuelTank);

    void setTirePack(const TirePack &tirePack);

    void setWeight(double weight);

    void setMileage(unsigned int mileage);

};
