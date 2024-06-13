#include "Engines.h"
#include<iostream>

Engines::Engines(unsigned  identifier, const MyString& manufacturerName, const MyString& description, double horsePower)
	: CarPart(identifier, manufacturerName, description) 
{
	this->horsePower = horsePower;
}

double  Engines::getHp()const
{
	return horsePower;
}

std::ostream& operator<<(std::ostream& os, const Engines& engines) 
{
	os << (const CarPart&)engines << engines.getHp();
	return os;
}