#include <iostream>

<<<<<<< Updated upstream
using std::cin, std::cout, std::endl;

void inputElements(int *arr, const int N) {
    for (int i = 0; i < N; i++) {
        cout << "Enter the " << i + 1 << " element: ";
        cin >> arr[i];
    }
}

int countSymbol(const int *arr, const int N, const char symbol) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] > (int) symbol) {
            count++;
        }
    }
    return count;
=======
int countSymbol(int* array, int size, char ch, int counter = 0)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] >= ch)
			counter++;
	}
	return counter;
}

int main()
{
	int N;
	cout << "Enter the number of elements in the array: ";
	cin >> N;
	int* array = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> array[i];
	}
	char symbol;
	cout << "Enter the symbol: ";
	cin >> symbol;
	cout << countSymbol(array, N, symbol);
	delete[] array;
>>>>>>> Stashed changes
}

int main() {
    int N;
    cout << "Enter the number of elements in the array: ";
    cin >> N;

    int *arr = new int[N];
    inputElements(arr, N);

    char symbol;
    cout << "Enter the symbol: ";
    cin >> symbol;

    cout << "The number of elements greater than the symbol: " << countSymbol(arr, N, symbol) << endl;
    
    delete[] arr;
    return 0;
}
