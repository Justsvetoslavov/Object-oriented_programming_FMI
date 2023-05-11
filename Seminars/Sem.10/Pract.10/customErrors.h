#pragma once
#include <iostream>

class insufficient_fuel_error : std::logic_error {
public:
	insufficient_fuel_error(const char* message) : logic_error(message) {};
};