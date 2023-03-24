#include <iostream>

void Print(const int* arr, size_t length)
{
	for (size_t i = 0; i < length; i++) {
		std::cout << arr[i] << " ";
	}
}

void InsertionSort(int* arr, size_t length)
{
	for (size_t i = 1; i < length; i++) {
		int currentNumber = arr[i];

		int j = i - 1;
		while (j >= 0 && arr[j] > currentNumber) {
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = currentNumber;
	}
}

int main()
{
	int arr[] = { 9, 5, 6, 3, 4, 7, 2, 1, 8 };

	InsertionSort(arr, 9);
	Print(arr, 9);
}