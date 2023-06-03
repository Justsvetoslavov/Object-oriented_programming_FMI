#pragma once
#include <iostream>
#include "MyString.h"

class insufficient_fuel_error : std::logic_error
{
public:

    insufficient_fuel_error(const MyString& ERROR);
};
