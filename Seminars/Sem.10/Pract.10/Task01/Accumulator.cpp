#include "Accumulator.h"

Accumulator::Accumulator(int id, const char* name, const char* details, int capacity, const char* batteryId) : 
CarPart(id, name, details){
	if (capacity < 0)
		throw std::out_of_range("The capacity cannot be less than 0");
	this->capacity = capacity;
	this->batteryId = batteryId;
}

std::ostream& operator<<(std::ostream& os, const Accumulator& other){
	os << (CarPart&)other << " - " << other.capacity << " Ah";
	return os;
}
