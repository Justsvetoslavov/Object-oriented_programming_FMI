#pragma once
#include "String.h"
#include <fstream>

class CarPart{
protected:
	unsigned id;
	String name;
	String details;

public:
	CarPart() = default;
	CarPart(int id, const char* name, const char* details);
    friend std::ostream& operator<<(std::ostream& os, const CarPart& other);
};

std::ostream& operator<<(std::ostream& os, const CarPart& other);

