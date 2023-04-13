#include <iostream>
#include "Date.h"

int main()
{
    Date d1(15, 10, 2023);
    Date d2(6, 11, 2024);
    std::cout << d1.IsEarlierThan(d2) << std::endl;
    std::cout << d1.DaysToChristmas() << std::endl;
    std::cout << d1.IsLeapYear() << std::endl;
    std::cout << d1.DaysToEvent(d2) << std::endl;
}

