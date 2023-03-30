#include <iostream>
#include "Date.h"

int main()
{
    int day, month, year;
    std::cin >> day >> month >> year;

    Date date(day,  month, year);

    date.Increase(4);

    date.Print();

    date.Decrease(4);

    date.Print();

}

