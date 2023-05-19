#include "Accumulator.h"

Accumulator::Accumulator(unsigned id, const MyString& manufacturerName, const MyString& descripiton,
	unsigned capacity, const MyString& batteryId) : CarPart(id, manufacturerName, descripiton){
	SetCapacity(capacity);
	this->batteryId = batteryId;
}

void Accumulator::SetCapacity(unsigned capacity) {
	if (capacity < 0)
		throw std::invalid_argument("Capacity should be at least 0!");
	this->capacity = capacity;
}

std::ostream& operator<<(std::ostream& os, const Accumulator& accumulator) {
	os << (CarPart&) accumulator << " - " << accumulator.batteryId << "Ah";
	return os;
}