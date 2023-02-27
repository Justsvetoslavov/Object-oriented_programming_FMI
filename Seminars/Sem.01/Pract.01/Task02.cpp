#include <iostream>


void inputArr(int* arr, const int SIZE)
{
	for (int i = 0; i < SIZE; ++i)
	{
		std::cout << "Enter element: ";
		std::cin >> arr[i];
	}
}

int countBiggerSymbols(const int* arr, const int SIZE, const char symbol)
{ 
	int counter = 0;
	for (int i = 0; i < SIZE; ++i)
	{
		if (arr[i] > symbol)
		{
			counter++;
		}
	}
	return counter;
}

int main()
{
	int N = 0;
	std::cout << "Enter N: ";
	std:: cin >> N;

	int* arr = new int[N];
	inputArr(arr, N);

	char symbol;
	std::cout << "Enter symbol: ";
	std::cin >> symbol;

	std::cout << "The number of the elements greater than symbol is: " << countBiggerSymbols(arr, N, symbol) << std::endl;

	delete[] arr;
}
