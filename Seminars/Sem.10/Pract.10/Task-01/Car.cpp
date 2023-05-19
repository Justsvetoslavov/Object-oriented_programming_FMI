
#include "Car.h"
#include "insufficient_fuel_error.h"


Car::Car(Engine *e, Tire *t, Accumulator *a, const FuelTank &ft, double weight)
        : engine{e}, tires{t}, accumulator{a}, tank{ft}, km{0}, weight{weight} {}

Car::Car(Engine *e, Tire *t, Accumulator *a, double fuelTankCapacity, double weight)
        : Car(e, t, a, FuelTank(fuelTankCapacity), weight) {}

const FuelTank &Car::getFuelTank() const {
    return tank;
}

double Car::weightHorsePower() const {
    return weight / engine->getHorsePower();
}

void Car::drive(double dist) {
    this->km += dist;
    tank.use(dist);
}

Car *dragRace(Car *car1, Car *car2) {
    static const double dist = 0.4;
    if (!car1 && !car2) {
        return nullptr;
    }

    if (!car1) {
        try {
            car2->drive(dist);
            return car2;
        } catch (insufficient_fuel_error &) {
            return nullptr;
        }
    }

    if (!car2) {
        try {
            car1->drive(dist);
            return car1;
        } catch (insufficient_fuel_error &) {
            return nullptr;
        }
    }

    try {
        car1->drive(dist);
        try {
            car2->drive(dist);
            return (car1->weightHorsePower() > car2->weightHorsePower()) ?
                   car1 : car2;
        } catch (insufficient_fuel_error &) {
            return car1;
        }
    } catch (insufficient_fuel_error &) {
        try {
            car2->drive(dist);
            return car2;
        } catch (insufficient_fuel_error &) {
            return nullptr;
        }
    }
}
