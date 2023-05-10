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
    } else
        throw std::logic_error("Used more petrol than car has");
}

unsigned int Car::getHorsePower() const {
    return engine.getHorsePower();
}

Car* dragRace(Car* car1, Car* car2) {
    int res = 0;
    try {
        car1->drive(0.4);
    } catch (const std::logic_error& exc) {
        res++;
    }
    try {
        car2->drive(0.4);
    } catch (const std::logic_error& exc) {
        if (res > 0)
            return nullptr;
        return car1;
    }
    if (res > 0)
        return car2;
    if (car1->getHorsePower() == car2->getHorsePower()) {
        if (car2->weight == car1->weight)
            return nullptr;
        else {
            if (car2->weight > car1->weight)
                return car2;
            return car1;
        }
    }
    else {
        if (car1->getHorsePower() > car2->getHorsePower())
            return car1;
        return car2;
    }
}