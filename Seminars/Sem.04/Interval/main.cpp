#include <iostream>
#include "Interval.h"

int main()
{
	Interval i(1, 11);

	std::cout << i.CalcDiffrentDigitNumbersInTheInverval() << std::endl;

	std::cout << i.GetLength() << std::endl;
}
