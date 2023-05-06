#include "insufficient_fuel_error.h"

insufficient_fuel_error::insufficient_fuel_error(const MyString& ERROR) : std::logic_error(ERROR.c_str()) {};