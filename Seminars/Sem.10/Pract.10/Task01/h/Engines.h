#pragma once
#include<iostream>
#include"CarPart.h"

class Engines :public CarPart
{
	double horsePower;

public:
	Engines(unsigned  identifier, const MyString& manufacturerName, const MyString& description, double horsePower);
	double  getHp()const;

};
std::ostream& operator<<(std::ostream& os, const Engines& engines);