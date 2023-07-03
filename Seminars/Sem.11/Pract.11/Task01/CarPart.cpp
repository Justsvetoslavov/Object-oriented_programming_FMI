#include "CarPart.h"

CarPart::CarPart(unsigned ID, MyString manufacturer, MyString description) {
	setID(ID);
	setManufacturer(manufacturer);
	setDescription(description);
}

void CarPart::setID(unsigned ID) {
	if (ID > 0) {
		_ID = ID;
	}
}

unsigned CarPart::getID() const {
	return _ID;
}

void CarPart::setManufacturer(MyString manufacturer) {
	_manufacturer = manufacturer;
}

const MyString& CarPart::getManufacturer() const {
	return _manufacturer;
}

void CarPart::setDescription(MyString description) {
	_description = description;
}

const MyString& CarPart::getDescription() const {
	return _description;
}

std::ostream& operator << (std::ostream& os, const CarPart& c) {
	return os << c.getID() << " by " << c.getManufacturer() << " - " << c.getDescription();
}
