#include "CarPart.h"

void CarPart::free() {
    delete[] manufacture;
    delete[] description;
    id = 0;
}

void CarPart::copyFrom(const CarPart &part) {
    manufacture = new char[strlen(part.manufacture) + 1];
    strcpy(manufacture ,part.manufacture);
    description = new char[strlen(part.description) + 1];
    strcpy(description, part.description);
    id = part.id;
}

CarPart::CarPart() {
    manufacture = new char[1];
    manufacture[0] = '\0';
    description = new char[1];
    description[0] = '\0';
    id = 0;
}

CarPart::CarPart(const CarPart &part) {
    copyFrom(part);
}

CarPart &CarPart::operator=(const CarPart &part) {
    if (this != &part) {
        free();
        copyFrom(part);
    }
    return *this;
}

CarPart::CarPart(int id, const char *name, const char *description) {
    if (id < 0)
        throw std::invalid_argument("Invalid id");
    this->id = id;
    this->manufacture = new char[strlen(name) + 1];
    strcpy(this->manufacture, name);
    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
}

CarPart::~CarPart() {
    free();
}

std::ostream& operator<<(std::ostream& os, const CarPart& part) {
    os  << '(' << part.id << ')' << " by " << part.manufacture << " - " << part.description;
    return os;
}