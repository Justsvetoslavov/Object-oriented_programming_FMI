#include "CarPart.h"
#include <cstring>
#include <stdexcept>

CarPart::CarPart(unsigned int ID, const char *manufacturer, const char *description)
{
	if (!manufacturer || !description)
		throw std::invalid_argument("Invalid input data. Nullptr provided.");

	_ID = ID;

	_manufacturer = new char[strlen(manufacturer) + 1];
	strcpy(_manufacturer, manufacturer);

	_description = new char[strlen(description) + 1];
	strcpy(_description, description);
}

CarPart::CarPart(const CarPart &other)
{
	copyFrom(other);
}

CarPart &CarPart::operator=(const CarPart &other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

void CarPart::copyFrom(const CarPart &other)
{
	_ID = other._ID;
	copyManufacturer(other._manufacturer);
	copyDescription(other._description);
}

void CarPart::copyManufacturer(const char *data)
{
	if (!data)
		throw std::invalid_argument("Invalid input data. Nullptr provided.");

	_manufacturer = new char[strlen(data) + 1];
	strcpy(_manufacturer, data);
}

void CarPart::copyDescription(const char *data)
{
	if (!data)
		throw std::invalid_argument("Invalid input data. Nullptr provided.");

	_description = new char[strlen(data) + 1];
	strcpy(_description, data);
}

void CarPart::free()
{
	delete[] _manufacturer;
	delete[] _description;
	_manufacturer = nullptr;
	_description = nullptr;
	_ID = 0;
}

std::ostream &operator<<(std::ostream &out, const CarPart &obj)
{
	return out << "(" << obj._ID << ")"
			   << " by " << obj._manufacturer
			   << " - " << obj._description;
}
