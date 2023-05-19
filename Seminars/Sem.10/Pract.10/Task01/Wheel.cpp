#include "Wheel.h"

const int MIN_WIDTH = 155;
const int MAX_WIDTH = 365;
const int MIN_PROFILE = 30;
const int MAX_PROFILE = 80;
const int MIN_DIAMETER = 13;
const int MAX_DIAMETER = 21;

Wheel::Wheel(unsigned id, const MyString& manufacturerName, const MyString& descripiton,
	double width, double profile, double diameter) : CarPart(id, manufacturerName, descripiton) {
	SetDiameter(diameter);
	SetProfile(profile);
	SetWidth(width);
}

void Wheel::SetWidth(double width) {
	if (width > MAX_WIDTH || width < MIN_WIDTH)
		throw std::invalid_argument("Width should be between 155 and 365!");
	this->width = width;
}

void Wheel::SetProfile(double profile) {
	if (profile > MAX_PROFILE|| profile < MIN_PROFILE)
		throw std::invalid_argument("Profile should be between 30 and 80!");
	this->profile = profile;
}

void Wheel::SetDiameter(double diameter) {
	if (diameter > MAX_DIAMETER || diameter < MIN_DIAMETER)
		throw std::invalid_argument("Diameter should be between 30 and 80!");
	this->diameter = diameter;
}

std::ostream& operator<<(std::ostream& os, const Wheel& wheel) {
	os << (CarPart&) wheel << " - " << wheel.width << "/"
		<< wheel.profile << "R" << wheel.diameter;
	return os;
}