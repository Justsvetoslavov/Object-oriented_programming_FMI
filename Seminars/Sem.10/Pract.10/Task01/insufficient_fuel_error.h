#pragma once

#include <stdexcept>

class insufficient_fuel_error : public std::logic_error {
public:
	insufficient_fuel_error() : std::logic_error("You have attempted to use more fuel than is available.") {

	}
};