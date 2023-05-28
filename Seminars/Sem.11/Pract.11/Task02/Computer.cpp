#include "Computer.h"
#include <stdexcept>
#include <cstring>

#pragma warning(disable : 4996)

Computer::Computer(double processorPower, const char *videoCardSerialNum, int powerSupply, int RAM)
{
    setVideoCardSerialNum(videoCardSerialNum);
    setProcessorPower(processorPower);
    setRAM(RAM);
}

Computer::Computer(const Computer &other)
{
    copyFrom(other);
}

Computer &Computer::operator=(const Computer &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Computer::~Computer()
{
    free();
}

void Computer::setProcessorPower(double processorPower)
{
    if (processorPower < 0)
        throw std::invalid_argument("Invalid processorPower value.");
    _processorPower = processorPower;
}

void Computer::free()
{
    delete[] _videoCardSerialNum;
}

void Computer::copyFrom(const Computer &other)
{
    _processorPower = other._processorPower;
    _powerSupply = other._powerSupply;
    setVideoCardSerialNum(other._videoCardSerialNum);
    _RAM = other._RAM;
}

void Computer::setVideoCardSerialNum(const char *videoCardSerialNum)
{
    unsigned size = strlen(videoCardSerialNum);
    if (size == 0)
        throw std::invalid_argument("Invalid video card serial number.");

    _videoCardSerialNum = new char[size + 1];
    strcpy(_videoCardSerialNum, videoCardSerialNum);
}

void Computer::setPowerSupply(int powerSupply)
{
    if (powerSupply < 0)
        throw std::invalid_argument("Invalid power supply value.");
    _powerSupply = powerSupply;
}

void Computer::setRAM(int RAM)
{
    if (RAM < 0)
        throw std::invalid_argument("Invalid RAM value.");
    _RAM = RAM;
}
