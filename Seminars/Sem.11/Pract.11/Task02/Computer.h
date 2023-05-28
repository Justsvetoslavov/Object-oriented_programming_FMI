#pragma once

class Computer
{
    double _processorPower = 0;
    char *_videoCardSerialNum = nullptr;
    int _powerSupply = 0;
    int _RAM = 0;

public:
    Computer(double, const char *, int, int);
    Computer(const Computer &);
    Computer &operator=(const Computer &);
    virtual ~Computer();

    void setProcessorPower(double);
    void setVideoCardSerialNum(const char *);
    void setPowerSupply(int);
    void setRAM(int);

public:
    virtual void computerType() const = 0;
    virtual void availablePeripherals() const = 0;

private:
    void free();
    void copyFrom(const Computer &);
};