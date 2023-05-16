#pragma once
#include <sstream>
#include "String.h"
class insufficient_fuel_error : public std::logic_error{
private:
	String error;

public:
	insufficient_fuel_error(const char* error);
};

