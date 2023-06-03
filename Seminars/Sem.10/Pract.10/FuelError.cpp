#include "FuelError.h"

FuelError::FuelError(const char *errMsg) : std::logic_error(errMsg) {}
