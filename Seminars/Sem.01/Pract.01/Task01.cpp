#include <iostream>

int LowerNumberByCopy(const int num1, const int num2)
{
	return num1 < num2 ? num1 : num2;
}

int LowerNumberByReference(const int& num1, const int& num2) 
{
	return num1 < num2 ? num1 : num2;
}

int LowerNumberByPointer(const int* num1, const int* num2) 
{
	return *num1 < *num2 ? *num1 : *num2;
}

int main() 
{
	int num1, num2;
	std::cin >> num1 >> num2;

	std::cout << LowerNumberByCopy(num1, num2) << std::endl;
	std::cout << LowerNumberByReference(num1, num2) << std::endl;
	std::cout << LowerNumberByPointer(&num1, &num2) << std::endl;
}