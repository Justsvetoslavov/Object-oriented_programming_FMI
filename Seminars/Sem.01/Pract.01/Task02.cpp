#include<iostream>
using std::cout;
using std::cin;
using std::endl;
//Natalia Nakollofski   1MI8000034    GR.1

//Прочетете цяло число N от стандартния вход, последвано от N на брой цели числа.
//Прочетете един символ от стандартния вход.Намерете броя на тези цели числа от
//въведените, които са по - големи от ASCII кода на символа.За целта използвайте динамична памет и функции.



void inputarray(int* arr, const int N) {

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

int findnr(const int* arr, const int N, char symbol) {
	int number = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] > int(symbol)) {
			number++;
		}

	}
	return number;
}


int main() {
	int N;
	cin >> N;
	int* arr = new int[N];
	inputarray(arr, N);
	char symbol;
	cin >> symbol;
	cout << findnr(arr, N, symbol);
	delete[]arr;
	return 0;
}
