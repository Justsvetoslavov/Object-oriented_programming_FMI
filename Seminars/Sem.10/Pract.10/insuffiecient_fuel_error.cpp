#include "insufficient_fuel_error.hpp"

const char* insufficient_fuel_error::what()
{
	return "Insufficient fuel";
}