#include "CarPart.h"

CarPart::CarPart()
{
	this->manufacturer = "Unknown manufacturer";
	this->description = "Unknown description";
}

CarPart::CarPart(const unsigned id, const char* manufacturer, const char* description)
{
	this->id = id;
	this->manufacturer = MyString{ manufacturer };
	this->description = MyString{ description };
}

std::ostream& operator<<(std::ostream& ofs, const CarPart& carPart)
{
	ofs << '(' << carPart.id << ") by " << carPart.manufacturer << " - " << carPart.description;
	return ofs;
}
