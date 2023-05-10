#pragma once
#include <cstring>
#include <iostream>

class Computer {
    double power;
    char* model;
    int consumption;
    int ram;

    void free();

    void copyFrom(const Computer& comp);

public:
    Computer();
    Computer(const Computer& comp);
    Computer& operator=(const Computer& comp);
    virtual ~Computer();

    double getPower() const;

    char *getModel() const;

    int getConsumption() const;

    int getRam() const;

    void setPower(double power);

    void setModel(const char *model);

    void setConsumption(int consumption);

    void setRam(int ram);

    virtual void GetType() const = 0;

    virtual void GetDevices() const = 0;
};
