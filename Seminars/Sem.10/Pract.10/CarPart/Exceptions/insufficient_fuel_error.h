#pragma once
#include <iostream>

class insufficient_fuel_error : protected  std::logic_error{

public:

    explicit insufficient_fuel_error(const char * message) noexcept : std::logic_error(message){}

};