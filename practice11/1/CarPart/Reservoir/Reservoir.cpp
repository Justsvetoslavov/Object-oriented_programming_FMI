#include "Reservoir.h"

Reservoir::Reservoir(int id, const char *name, const char *desc, double volume) : CarPart(id, name, desc) {
    if (volume < 0)
        throw std::invalid_argument("Invalid value");
    this->volume = this->petrol = volume;
}

void Reservoir::fill(double toFill) {
    if (toFill < 0)
        throw std::logic_error("Negative filling :/");
    petrol = (toFill + petrol >= volume ? volume : toFill + petrol);
}

void Reservoir::use(double toUse) {
    if (toUse > petrol)
        throw std::logic_error("Used more petrol than we have");
    petrol -= toUse;
}

double Reservoir::getPetrol() const {
    return petrol;
}