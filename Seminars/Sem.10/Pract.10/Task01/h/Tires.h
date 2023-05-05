#pragma once
#include "CarPart.h"
#include<iostream>

const int min_width = 155;
const int max_width = 365;
const int min_profile = 30;
const int  max_profile = 80;
const int min_diameter = 13;
const int  max_diameter = 21;

class Tires:public CarPart
{
	double  width;
	double  profile;
	double  diameter;

public:

	Tires() = default;
	Tires(unsigned identifier, const MyString& manufacturerName, const MyString& description, double   width, double  profile, double diameter);

	void setWidth(double width);
	void setProfile(double profile);
	void setDiameter(double diameter);

	double  getWidth()const;
	double  getProfile()const;
	double  getDiameter()const;

};

std::ostream& operator<<(std::ostream& os, const Tires& tires);