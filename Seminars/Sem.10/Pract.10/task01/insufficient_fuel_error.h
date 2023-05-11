#ifndef PRACT010_INSUFFICIENT_FUEL_ERROR_H
#define PRACT010_INSUFFICIENT_FUEL_ERROR_H
#include <iostream>
#include "MyString.h"
const MyString MESSAGE="NO FUEL";

class insufficient_fuel_error:public std::logic_error {
public:
    insufficient_fuel_error(const MyString& message);
};


#endif //PRACT010_INSUFFICIENT_FUEL_ERROR_H
