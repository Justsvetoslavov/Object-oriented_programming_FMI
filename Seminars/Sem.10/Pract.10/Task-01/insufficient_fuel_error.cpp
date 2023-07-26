#include "insufficient_fuel_error.h"

insufficient_fuel_error::insufficient_fuel_error(const char *error)
        : logic_error(error) {}
