#include "Tir.h"

void Tir::GetPermit() const {
    std::cout << "Only on highway\n";
}

Tir::Tir(const Tires *_tires, unsigned int countT, const EngineType &_type, unsigned int countP, double averageS)
        : Vehicle(_tires, countT, _type, countP, averageS) {
    if (countT < 6 || countT > 16)
        throw std::logic_error("Incorrect count of tires!");
}