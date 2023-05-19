#pragma once

#include <stdexcept>

class insufficient_fuel_error : public std::logic_error {
public:
    explicit insufficient_fuel_error(const char *error);
};