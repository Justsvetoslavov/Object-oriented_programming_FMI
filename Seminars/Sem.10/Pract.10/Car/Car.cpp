#include "Car.h"


Car::Car(const Engine& _engine,const Battery& _battery,const FuelTank& _fuelTank,const TirePack& _tirePack,
    double _weight,unsigned int _mileage)
    :engine(_engine), battery(_battery), fuelTank(_fuelTank), tirePack(_tirePack){

    weight = _weight;
    mileage = _mileage;

}
Car::Car(Engine&& _engine, Battery&& _battery, FuelTank&& _fuelTank, TirePack&& _tirePack,
    double _weight,unsigned int _mileage)
    :engine(_engine), battery(std::move(_battery)), fuelTank(_fuelTank), tirePack(std::move(_tirePack)){

    weight = _weight;
    mileage = _mileage;
}

const FuelTank& Car::getFuelTank() const{
    return fuelTank;
}

void Car::drive(double km){

    if(km < 0)throw std::invalid_argument("km cannot be < 0");
    mileage += km;
    try{
        fuelTank.use(km);
    }catch(insufficient_fuel_error&){
        std::cout<<"bitten tanken";
    }
}

const Engine &Car::getEngine() const {
    return engine;
}

const Battery &Car::getBattery() const {
    return battery;
}

const TirePack &Car::getTirePack() const {
    return tirePack;
}

double Car::getWeight() const {
    return weight;
}

unsigned int Car::getMileage() const {
    return mileage;
}
void Car::setEngine(const Engine &engine) {
    Car::engine = engine;
}
void Car::setBattery(const Battery &battery) {
    Car::battery = battery;
}
void Car::setFuelTank(const FuelTank &fuelTank) {
    Car::fuelTank = fuelTank;
}

void Car::setTirePack(const TirePack &tirePack) {
    Car::tirePack = tirePack;
}

void Car::setWeight(double weight) {
    Car::weight = weight;
}

void Car::setMileage(unsigned int mileage) {
    Car::mileage = mileage;
}
