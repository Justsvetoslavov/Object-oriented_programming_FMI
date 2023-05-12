#include "CarPart.h"

CarPart::CarPart(unsigned id, const MyString& manufacturerName, const MyString& descripiton) {
	this->id = id;
	this->manufacturerName = manufacturerName;
	this->descripiton = descripiton;
}

const MyString& CarPart::GetManufacturerName() const {
	return this->manufacturerName;
}

const MyString& CarPart::GetDescription() const {
	return this->descripiton;
}

std::ostream& operator<<(std::ostream& os, const CarPart& carPart) {
	os << "(" << carPart.id << ") by " << carPart.manufacturerName << " - "
		<< carPart.descripiton;
	return os;
}