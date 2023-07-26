#include "CarPart.h"
#include <cstring>

CarPart::CarPart() : CarPart(0, "fmi", "info") {}

CarPart::CarPart(unsigned int id, const char *manufacturer, const char *description)
        : id{id} {
    copy(this->manufacturer, manufacturer);
    copy(this->description, description);
}

CarPart::CarPart(const CarPart &other) {
    copyFrom(other);
}

CarPart::CarPart(CarPart &&other) noexcept {
    moveFrom(std::move(other));
}

CarPart &CarPart::operator=(const CarPart &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

CarPart &CarPart::operator=(CarPart &&other) noexcept {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

CarPart::~CarPart() {
    free();
}

void CarPart::free() {
    delete[] manufacturer;
    delete[] description;
    manufacturer = description = nullptr;
}

void CarPart::copyFrom(const CarPart &other) {
    id = other.id;
    copy(manufacturer, other.manufacturer);
    copy(description, other.description);
}

void CarPart::moveFrom(CarPart &&other) {
    id = other.id;
    manufacturer = other.manufacturer;
    description = other.description;

    other.manufacturer = other.description = nullptr;
}

void CarPart::copy(char *dest, const char *src) {
    dest = new char[strlen(src) + 1];
    strcpy(dest, src);
}

unsigned CarPart::getId() const {
    return id;
}

const char *CarPart::getManufacturer() const {
    return manufacturer;
}

const char *CarPart::getDescription() const {
    return description;
}

void CarPart::setId(unsigned int id) {
    this->id = id;
}

void CarPart::setManufacturer(const char *manufacturer) {
    delete[] this->manufacturer;
    copy(this->manufacturer, manufacturer);
}

void CarPart::setDescription(const char *description) {
    delete[] this->description;
    copy(this->description, description);
}


std::ostream &operator<<(std::ostream &os, const CarPart &part) {
    return os << '(' << part.getId() << ") by " << part.getManufacturer()
              << " - " << part.getDescription() << " - ";
}
