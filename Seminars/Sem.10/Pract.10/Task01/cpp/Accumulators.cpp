#include "Accumulators.h"
#include<iostream>

Accumulators::Accumulators(unsigned  identifier, const MyString& manufacturerName, const MyString& description, unsigned  capacity, const MyString& batteryId) :
	CarPart(identifier, manufacturerName, description)
{
	this->capacity = capacity;
	this->batteryId = batteryId;
}

unsigned  Accumulators::getCapacity()const 
{
	return capacity;
}

MyString Accumulators::getBatteryId()const 
{
	return batteryId;
}

std::ostream& operator<<(std::ostream& os, const Accumulators& accumulators) 
{
	os << (const CarPart&)accumulators << "Capacity in Ah :" << accumulators.getCapacity() << "BatteryId" << accumulators.getBatteryId() << std::endl;
	return os;
}