
#pragma once

#include <stdexcept>

class FuelError : public std::logic_error {
public:
    FuelError(const char *errMsg);
};


