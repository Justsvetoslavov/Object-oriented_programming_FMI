#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int countDigits(int* array, int size, char ch, int counter = 0)
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
	char ch;
	cout << "Enter the symbol: ";
	cin >> ch;
	cout << countDigits(array, N, ch);
	delete[] array;
}

