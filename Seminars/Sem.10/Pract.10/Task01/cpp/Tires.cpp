#include "Tires.h"
#include<iostream>

Tires::Tires(unsigned identifier, const MyString& manufacturerName, const MyString& description, double  width, double   profile, double diameter)
	:CarPart( identifier,  manufacturerName, description)
{
	setWidth(width);
	setProfile(profile);
	setDiameter(diameter);

}

double  Tires::getWidth()const 
{
	return width;
}

double Tires::getProfile()const 
{
	return profile;
}

double Tires::getDiameter()const 
{
	return diameter;
}

std::ostream& operator<<(std::ostream& os, const Tires& tires)
{
	os << (const CarPart&)tires <<"Width" << tires.getWidth() <<"Profile" << tires.getProfile() <<"Diameter" << tires.getDiameter()<<std::endl;
	return os;
}

void Tires::setWidth(double width) 
{
	if (width >= min_width && width <= max_width)
	{
		this->width = width;
	}
	else 
	{
		throw std::out_of_range("Invalid width.");
	}
}

void Tires::setProfile(double profile) 
{
	if (profile >= min_profile && profile <= max_profile)
	{
		this->profile = profile;
	}
	else
	{
		throw std::out_of_range("Invalid profile.");
	}
}

void Tires::setDiameter(double diameter) 
{
	if (diameter >= min_diameter && diameter <= max_diameter) 
	{
		this->diameter = diameter;
	}
	else
	{
		throw std::out_of_range("Invalid diameter.");
	}
}