#pragma once
#include<iostream>
#include "MyString.h"

class CarPart
{
	unsigned identifier;
	MyString manufacturerName;
	MyString description;

public:
	CarPart() = default;
	CarPart(unsigned  identifier, const MyString& manufacturerName, const MyString& description);
	unsigned  getIdentifier()const;
	MyString getManufacturerName()const;
	MyString getDescription()const;
};

std::ostream& operator<<(std::ostream& os, const CarPart&carPart);
