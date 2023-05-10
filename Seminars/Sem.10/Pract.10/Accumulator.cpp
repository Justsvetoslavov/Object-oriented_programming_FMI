#include "CarPart.h"
#include "Accumulator.h"
#include <iostream>
#pragma warning (disable : 4996)

Accumulator::Accumulator()
{
	capacity = 0;
	batteryId = nullptr;
}

Accumulator::Accumulator(unsigned capacity, char* batteryId)
{
	setCapacity(capacity);
	setBatteryId(batteryId);
}

Accumulator::Accumulator(const Accumulator& other) : CarPart(other)
{
	copyFrom(other);
}

Accumulator& Accumulator::operator=(const Accumulator&other)
{
	if (this != &other)
	{
		CarPart::operator=(other);
		free();
		copyFrom(other);
	}
	return *this;
}

Accumulator::~Accumulator()
{
	free();
}

unsigned Accumulator::getCapacity() const
{
	return capacity;
}

char* Accumulator::getBatteryId() const
{
	return batteryId;
}

void Accumulator::setCapacity(unsigned capacity)
{
	this->capacity = capacity;
}

void Accumulator::setBatteryId(char* batteryId)
{
	if (batteryId == nullptr || strlen(batteryId) == 0 || this->batteryId == batteryId)
		return;
	delete[] this->batteryId;
	batteryId = new char[strlen(batteryId) + 1];
	strcpy(this->batteryId, batteryId);
}

void Accumulator::copyFrom(const Accumulator& other)
{
	capacity = other.capacity;
	batteryId = new char[strlen(other.batteryId) + 1];
	strcpy(batteryId, other.batteryId);
}

void Accumulator::free()
{
	delete[] batteryId;
}

std::ostream& operator<<(std::ostream os, const Accumulator& accumulator)
{
	os << (CarPart&)accumulator << accumulator.getCapacity() << " Ah";
}
