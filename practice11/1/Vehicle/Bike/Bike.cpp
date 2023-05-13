#include "Bike.h"

void Bike::GetPermit() const {
    std::cout << "Only in city\n";
}

Bike::Bike(const Tires *_tires, unsigned int countT, const EngineType &_type, unsigned int countP, double averageS)
        : Vehicle(_tires, countT, _type, countP, averageS) {
    if (countT < 2 || countT > 4)
        throw std::logic_error("Incorrect count of tires!");
}