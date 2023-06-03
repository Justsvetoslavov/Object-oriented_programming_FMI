#include "Car.h"


Car::Car(const FuelTank &&fullTank, const Engine &&engine1, const Tire *tires, const Accumulator &&accumulator1,
         double km, double mass) :
        tank(fullTank), engine(engine1), accumulator(accumulator1), kilometers(km), mass(mass) {
    for (int i = 0; i < 4; ++i) {
        this->tires[i] = tires[i];
    }
}

const FuelTank &Car::getFuelTank() {
    return this->tank;
}

void Car::drive(double km) {
    tank.use(km);

    kilometers += km;
}

const Engine &Car::getEngine() {
    return this->engine;
}

double Car::getMass() const {
    return this->mass;
}

Car *dragRace(Car *car1, Car *car2) {
    bool has1Fuel = car1->getFuelTank().getFuel() >= 0.4;
    bool has2Fuel = car2->getFuelTank().getFuel() >= 0.4;

    if (!has2Fuel && !has1Fuel) {
        return nullptr;
    }

    if (has1Fuel) {
        car1->drive(0.4);
        if (!has2Fuel) {
            return car1;
        }
    }

    car2->drive(0.4);
    if (!has1Fuel) {
        return car2;
    }


    return (car1->getEngine().getHorsePower() / car1->getMass()) > (car2->getEngine().getHorsePower() / car2->getMass())
           ? car1 : car2;

}
