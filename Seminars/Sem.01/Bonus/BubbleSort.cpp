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

void BubbleSort(int* arr, size_t length)
{
	for (size_t i = 0; i < length - 1; i++) {
		bool hasSwaps = false;

		// last i numbers are already ordered
		for (size_t j = 0; j < length - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				Swap(arr[j], arr[j + 1]);
				hasSwaps = true;
			}
		}

		if (!hasSwaps) {// if no swaps were made - array is ordered
			break;
		}
	}
}

int main()
{
	int arr[] = { 9, 5, 6, 3, 4, 7, 2, 1, 8 };

	BubbleSort(arr, 9);
	Print(arr, 9);
}
