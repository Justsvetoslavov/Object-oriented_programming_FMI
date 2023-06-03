#pragma once
#include "MyString.h"
#include <fstream>

class CarPart
{
protected:
	unsigned id = 0;
	MyString manufacturer;
	MyString description;

	CarPart();
	CarPart(unsigned id, const char* manufacturer, const char* description);

	friend std::ostream& operator<<(std::ostream& ofs, const CarPart& carPart);
};

std::ostream& operator<<(std::ostream& ofs, const CarPart& carPart);

