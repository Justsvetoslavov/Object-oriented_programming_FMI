#include <iostream>

int countOfNumbers(int* arr, int arrCount, char symbol)
{
	int count = 0;
	for (size_t i = 0; i < arrCount; i++)
	{
		if (arr[i] > symbol) count++;
	}
	return count;
}

int main()
{
	int n;
	do
	{
		std::cout << "Enter n: ";
		std::cin >> n;
	} while (n <= 0);
	
	int* arr = new int[n];
	for (size_t i = 0; i < n; i++) std::cin >> arr[i];

	char symbol;
	std::cout << "Enter a symbol: ";
	std::cin >> symbol;

	std::cout << "The count of numbers that have a value higher than "
		<< symbol << " ASCII code is " 
		<< countOfNumbers(arr, n, symbol) << std::endl;

	delete[] arr;
	return 0;
}