#pragma once
#include "String.hpp"

class CarPart 
{
protected:
	unsigned int carPartId;
	String manufacturer;
	String description;
public:
	CarPart() = default;

	CarPart(unsigned int id, String manufacturer, String description);

	CarPart(const CarPart& other);

	CarPart& operator=(const CarPart& other);

	void setID(unsigned int id);

	void setManufacturer(String manufacturer);

	void setDescription(String description);

	~CarPart();
private:
	void free();
	void copyFrom(const CarPart& other);
};