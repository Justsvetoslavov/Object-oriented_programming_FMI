#include "insufficient_fuel_exception.h"

insufficient_fuel_exception::insufficient_fuel_exception(const char *msg) : std::logic_error(msg) {}
