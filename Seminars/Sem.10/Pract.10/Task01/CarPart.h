#pragma once
#include "MyString.h"
class CarPart
{
protected:
	unsigned id = 0;
	MyString manufacturerName;
	MyString descripiton;

public:
	CarPart() = default;
	CarPart(unsigned id, const MyString& manufacturerName, const MyString& descripiton);

	const MyString& GetManufacturerName() const;
	const MyString& GetDescription() const;

	friend std::ostream& operator<<(std::ostream& os, const CarPart& carPart);
};

