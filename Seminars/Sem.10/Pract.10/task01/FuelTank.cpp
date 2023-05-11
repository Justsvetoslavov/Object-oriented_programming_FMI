#include "FuelTank.h"
#include "insufficient_fuel_error.h"

FuelTank::FuelTank(unsigned int id, const MyString &name,
                   const MyString &description, double capacity):CarPart(id,name,description) {
    setCapacity(capacity);
    setLiters(liters);
}
double FuelTank::getLiters() const {
    return liters;
}

void FuelTank::setLiters(double liters) {
    if(liters<0){
        liters=0;
    }
    if(liters>capacity){
        liters=capacity;
    }
    FuelTank::liters = liters;
}

double FuelTank::getCapacity() const {
    return capacity;
}

void FuelTank::setCapacity(double capacity) {
    if(capacity<0){
        capacity=0;
    }
    FuelTank::capacity = capacity;
}

FuelTank &FuelTank::use(double liters) {
    if(FuelTank::liters<liters){
        throw insufficient_fuel_error(MESSAGE);
    }
    FuelTank::liters-=liters;
    return *this;
}

FuelTank &FuelTank::fill(double liters) {
    FuelTank::liters+=liters;
    if(FuelTank::liters>capacity){
        FuelTank::liters=capacity;
    }
}

std::ostream& operator<<(std::ostream& os,const FuelTank& ft){
    os<<(CarPart&)ft<<"- ";
    os<<ft.capacity<<"L "<<ft.liters<<"L ";
}


