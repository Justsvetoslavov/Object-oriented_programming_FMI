#include <iostream>

int lowerNumByCopie(const int num1, const int num2)
{
	return num1 < num2 ? num1 : num2;
}

int lowerNumByReference(const int& num1, const int& num2)
{
	return num1 < num2 ? num1 : num2;
}

int lowerNumByPointer(const int* num1, const int* num2)
{
	return *num1 < *num2 ? *num1 : *num2;
}

int main()
{
	int num1, num2;
	std::cin >> num1 >> num2;

	std::cout << lowerNumByCopie(num1, num2) << std::endl;
	std::cout << lowerNumByReference(num1, num2) << std::endl;
	std::cout << lowerNumByPointer(&num1, &num2) << std::endl;
}
	
