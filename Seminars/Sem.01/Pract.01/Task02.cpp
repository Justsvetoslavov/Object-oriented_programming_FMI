#include <iostream>
using namespace std;

void ReadArray(int&, int*&);
int CountOfNumbersBiggerThanASCII(char, int*, int);

int main() {
	int n;
	int* arr = nullptr;
	ReadArray(n, arr);
	char ch;
	cin >> ch;
	int result = CountOfNumbersBiggerThanASCII(ch,arr,n);
	cout << result << endl;
}

int CountOfNumbersBiggerThanASCII(char ch, int* arr, int n) {
	int result = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (arr[i] > ch) result++;
	}
	return result;
}

void ReadArray(int& n, int*& arr) {
	cin >> n;
	arr = new int[n];
	for (size_t i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}