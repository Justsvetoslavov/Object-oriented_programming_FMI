#include "insufficient_fuel_error.h"

insufficient_fuel_error::insufficient_fuel_error(const MyString& error)
	: std::logic_error(error.c_str()){}