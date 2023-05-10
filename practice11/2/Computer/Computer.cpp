//
// Created by grade on 5/10/2023.
//

#include "Computer.h"

double Computer::getPower() const {
    return power;
}

char *Computer::getModel() const {
    return model;
}

int Computer::getConsumption() const {
    return consumption;
}

int Computer::getRam() const {
    return ram;
}

void Computer::setPower(double power) {
    this->power = power;
}

void Computer::setModel(const char *model) {
    char *newModel = new char[strlen(model) + 1];
    strcpy(newModel, model);
    delete[] this->model;
    this->model = newModel;
}

void Computer::setConsumption(int consumption) {
    this->consumption = consumption;
}

void Computer::setRam(int ram) {
    this->ram = ram;
}

Computer::~Computer() {
    free();
}

Computer::Computer(const Computer &comp) {
    copyFrom(comp);
}

Computer &Computer::operator=(const Computer &comp) {
    if (this != &comp) {
        free();
        copyFrom(comp);
    }
    return *this;
}

Computer::Computer() {
    model = new char[1];
    model[0] = '\0';
    power = consumption = ram = 0;
}

void Computer::free() {
    delete[] model;
    power = consumption = ram = 0;
}

void Computer::copyFrom(const Computer &comp) {
    model = new char[strlen(comp.model) + 1];
    strcpy(model, comp.model);
    power = comp.power;
    consumption = comp.consumption;
    ram = comp.ram;
}

