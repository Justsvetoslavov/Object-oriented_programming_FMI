#pragma once
#include "MyString.h"
#include"CarPart.h"

class Accumulators :public CarPart
{
	unsigned  capacity;
	MyString  batteryId;

public:
	Accumulators(unsigned  identifier, const MyString& manufacturerName, const MyString& description, unsigned  capacity, const MyString& batteryId);
	unsigned  getCapacity()const;
	MyString getBatteryId()const;
};

std::ostream& operator<<(std::ostream& os, const Accumulators& accumulators);