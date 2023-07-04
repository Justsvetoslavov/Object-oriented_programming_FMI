#pragma once
#include <cstring>

class Device {
    char* model;

    void free();

    void copyFrom(const Device& device);
public:
    Device();
    ~Device();
    Device(const Device& device);

    Device& operator=(const Device& device);

    const char *getModel() const;
    void setModel(const char* md);
};
