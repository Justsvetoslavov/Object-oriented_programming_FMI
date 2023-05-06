#include "CarPart.hpp"
#include <cstring>

CarPart::CarPart(unsigned int id,String manufacturer, String description)
{
	this->carPartId = id;
	setManufacturer(manufacturer);
	setDescription(description);
}

CarPart::CarPart(const CarPart& other)
{
	copyFrom(other);
}

CarPart& CarPart::operator=(const CarPart& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

void CarPart::setID(unsigned int id)
{
	this->carPartId = id;
}

void CarPart::setManufacturer(String manufacturer)
{
	if (!manufacturer.isEmpthy())
	{
		this->manufacturer = manufacturer;
	}
	else
	{
		throw std::logic_error("Manufacturer can't be empty");
	}
}

void CarPart::setDescription(String description)
{
	if (!description.isEmpthy())
	{
		this->description = description;
	}
	else
	{
		throw std::logic_error("Description can't be empty");
	}
}

CarPart::~CarPart()
{
	free();
}

void CarPart::free()
{

}

void CarPart::copyFrom(const CarPart& other)
{
	this->carPartId = other.carPartId;
	setManufacturer(other.manufacturer);
	setDescription(other.description);
}