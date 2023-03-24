#include <iostream>

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Print(const int* arr, size_t length)
{
	for (size_t i = 0; i < length; i++) {
		std::cout << arr[i]<< " ";
	}
}

void SelectionSort(int* arr, size_t length)
{
	for (size_t i = 0; i < length - 1; i++) {
		size_t minIndex = i;

		// first i numbers are already ordered
		for (size_t j = i + 1; j < length; j++) {
			if (arr[minIndex] > arr[j]) {
				minIndex = j;
			}
		}

		if (minIndex != i) { // if minIndex changed - swap
			Swap(arr[i], arr[minIndex]);
		}
	}
}

int main()
{
	int arr[] = { 9, 5, 6, 3, 4, 7, 2, 1, 8 };

	SelectionSort(arr, 9);
	Print(arr, 9);
}