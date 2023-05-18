#include <iostream>
#include "Dates.h"

int main() 
{
    Date d1(31, Months::March, 2014);
    Date d2;
    d1.addDays(1);
    d1.removeDays(1);
    d1.daysToXmas();
    d1.isLeapYear();
    d1.isEarlierThan(d2);
} 