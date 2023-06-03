#include "CarPart.h"
#include <cstring>

CarPart::CarPart(unsigned int indetificator, const char *proizvoditel, const char *description) {
    setIndet(indetificator);
    setDesc(description);
    setProiz(proizvoditel);
}

CarPart::CarPart(const CarPart &other) {
    copyFrom(other);
}

CarPart &CarPart::operator=(const CarPart &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

CarPart::~CarPart() {
    free();
}

void CarPart::free() {
    delete description;
    delete proizvoditel;
    description = nullptr;
    proizvoditel = nullptr;
}

void CarPart::copyFrom(const CarPart &other) {
    setProiz(other.proizvoditel);
    setDesc(other.description);
    this->indetificator = other.indetificator;
}

void CarPart::setProiz(const char *proiz) {
    this->proizvoditel = new char[std::strlen(proiz)];
    strcpy(proizvoditel, proiz);
}

void CarPart::setDesc(const char *desc) {
    this->description = new char[std::strlen(desc)];
    strcpy(description, desc);
}

void CarPart::setIndet(unsigned int i) {
    if (i == 0) {
        return;
    }
    indetificator = i;
}

std::ostream &operator<<(std::ostream &os, const CarPart &carPart) {
    os << carPart.indetificator << " by " << carPart.proizvoditel << " - " << carPart.description;
    return os;
}

