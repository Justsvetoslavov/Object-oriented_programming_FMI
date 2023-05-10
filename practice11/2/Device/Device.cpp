#include "Device.h"

Device::Device() {
    model = new char[1];
    model[0] = '\0';
}

Device::Device(const Device &device) {
    copyFrom(device);
}

void Device::copyFrom(const Device &device) {
    model = new char[strlen(device.model) + 1];
    strcpy(model, device.model);
}

void Device::free() {
    delete[] model;
}

Device &Device::operator=(const Device &device) {
    if (this != &device) {
        free();
        copyFrom(device);
    }
    return *this;
}

Device::~Device() {
    free();
}

const char *Device::getModel() const {
    return model;
}

void Device::setModel(const char *md) {
    char* newModel = new char[strlen(md) + 1];
    strcpy(newModel, md);
    delete[] model;
    model = newModel;
}