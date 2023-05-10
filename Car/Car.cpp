#include "Car.h"

const double DIST = 0.4;

Car::Car(const Reservoir &reservoir, const Engine &engine, const Tires *tires, const Battery& battery,
         double mileage, double weight) : reservoir(reservoir), engine(engine), battery(battery) {
    if (mileage < 0 || weight < 0)
        throw std::invalid_argument("Invalid millage or weight");
    this->mileage = mileage;
    this->weight = weight;
    for (int i = 0; i < 4; ++i)
        this->tires[i] = tires[i];
}

const Reservoir &Car::getReservoir() const {
    return reservoir;
}

void Car::drive(double km) {
    if (km <= reservoir.getPetrol()) {
        mileage += km;
        reservoir.use(km);
    }
}

Car* dragRace(Car* car1, Car* car2) {

}