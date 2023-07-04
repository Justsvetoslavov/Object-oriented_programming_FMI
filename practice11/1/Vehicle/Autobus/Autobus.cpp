#include "Autobus.h"

void Autobus::GetPermit() const {
    std::cout << "In city, outside city\n";
}

Autobus::Autobus(const Tires *_tires, unsigned int countT, const EngineType &_type, unsigned int countP, double averageS)
        : Vehicle(_tires, countT, _type, countP, averageS) {
    if (countT < 4 || countT > 8)
        throw std::logic_error("Incorrect count of tires!");
}