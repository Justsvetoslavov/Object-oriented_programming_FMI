#include "CarPart.h"
#include<iostream>

CarPart::CarPart(unsigned  identifier, const MyString& manufacturerName, const MyString& description) 
{
	this->identifier = identifier;
	this->manufacturerName = manufacturerName;
	this->description = description;
}

unsigned  CarPart::getIdentifier()const
{
	return identifier;
}
MyString CarPart::getManufacturerName()const
{
	return manufacturerName;
 }
MyString CarPart::getDescription()const
{
	return description;
}
std::ostream& operator<<(std::ostream& os, const CarPart& carPart) 
{
	os << "Id:" << carPart.getIdentifier() << "by manufacturer:" << carPart.getManufacturerName() << "description:" << carPart.getDescription() << std::endl;
	return os;
}
