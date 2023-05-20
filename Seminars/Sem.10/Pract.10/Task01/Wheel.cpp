#include "Wheel.h"

Wheel::Wheel(int id, const char* name, const char* details, double width, double profile, double diameter)
: CarPart(id, name, details){
	SetWidth(width);
	SetProfile(profile);
	SetDiameter(diameter);
}

void Wheel::SetWidth(double width){
	if (width < 155 || width > 365)
		throw std::out_of_range("The width must be between 155 and 365!");

	this->width = width;
}

void Wheel::SetProfile(double profile) {
	if (profile < 30 || profile > 80)
		throw std::out_of_range("The profile must be between 30 and 80");

	this->profile = profile;
}

void Wheel::SetDiameter(double diameter){
	if (diameter < 13 || diameter > 21)
		throw std::out_of_range("The diameter must be between 13 and 21");

	this->diameter = diameter;
}

std::ostream& operator<<(std::ostream& os, const Wheel& other){
	os << (CarPart&)other << " - " << other.width << "/" << other.profile << "R" << other.diameter;
	return os;
}
