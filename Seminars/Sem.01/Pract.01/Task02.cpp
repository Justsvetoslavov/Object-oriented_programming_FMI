#include <iostream>

void InputArr(int* arr, const int size)
{
	for (size_t i = 0; i < size; i++) {
		std::cin >> arr[i];
	}
}

int CountBiggerSymbols(const int* arr, const int size, const char symbol) 
{ 
	int counter = 0;
	for (size_t i = 0; i < size; i++) {
		if (arr[i] > symbol) {
			counter++;
		}
	}

	return counter;
}

int main()
{
    int N;
    cout << "Enter the number of elements in the array: ";
    cin >> N;

    int *arr = new int[N];
    InputElements(arr, N);

    char symbol;
    cout << "Enter the symbol: ";
    cin >> symbol;

    cout << "The number of elements greater than the symbol: " << CountSymbol(arr, N, symbol) << endl;
    
    delete[] arr;
    return 0;
}
