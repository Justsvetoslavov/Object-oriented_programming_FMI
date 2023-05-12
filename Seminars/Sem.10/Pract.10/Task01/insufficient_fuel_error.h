#pragma once
#include <sstream>
#include "MyString.h"
class insufficient_fuel_error : std::logic_error
{
private:
	MyString error;
public:
	insufficient_fuel_error(const MyString& error);
};

