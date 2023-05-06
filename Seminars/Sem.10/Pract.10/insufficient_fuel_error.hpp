#pragma once
#include <iostream>

class insufficient_fuel_error : public std::logic_error
{
public:
	insufficient_fuel_error() : std::logic_error("Insufficient fuel") {}

	const char* what();
};