#pragma once

#include "MyString.h"

class CarPart {
	MyString _manufacturer = "Unknown";
	MyString _description = "Unknown";
	unsigned _ID = 1;

public:
	CarPart() = default;
	CarPart(unsigned ID, MyString manufacturer, MyString description);

	void setID(unsigned ID);
	unsigned getID() const;

	void setManufacturer(MyString manufacturer);
	const MyString& getManufacturer() const;

	void setDescription(MyString description);
	const MyString& getDescription() const;
};

std::ostream& operator << (std::ostream& os, const CarPart& c);