#include "Car.h"

void Car::GetPermit() const {
    std::cout << "Everywhere\n";
}

Car::Car(const Tires *_tires, unsigned int countT, const EngineType &_type, unsigned int countP, double averageS)
    : Vehicle(_tires, countT, _type, countP, averageS) {
    if (countT != 4 && countT != 3)
        throw std::logic_error("Incorrect count of tires!");
}