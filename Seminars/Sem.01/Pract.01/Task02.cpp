#include <iostream>

void inputArr(int* arr, size_t size);
void checkTheACIIDigit(int* arr, size_t size, char symbol);
bool isBigger(int num, char symbol);

int main()
{
	unsigned int n;
	std::cin >> n;
	int* arr = new int[n];
	inputArr(arr, n);
	char symbol;
	std::cin >> symbol;
	checkTheACIIDigit(arr, n, symbol);
	delete[] arr;

	return 0;
}

void inputArr(int* arr, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

void checkTheACIIDigit(int* arr, size_t size, char symbol)
{
	for (int i = 0; i < size; i++)
	{
		if (isBigger(arr[i], symbol))
		{
			std::cout << arr[i] << " ";
		}
	}
}

bool isBigger(int num, char symbol)
{
	return num > symbol;
}