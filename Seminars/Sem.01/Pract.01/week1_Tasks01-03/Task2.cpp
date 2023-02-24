#include <iostream>

void validation(int& positiveNumber) {
    while (positiveNumber < 0) {
        std::cout << "N should be positive!\nTry again: ";
        std::cin >> positiveNumber;
    }
}

void inputNumbers(int*& const numbers, int const length) {
    std::cout << "Input numbers from 1 to " << length << ": ";
    for (int i = 0; i < length; ++i) {
        std::cin >> numbers[i];
    }
}

bool isHigher(char& symbol, int const number) {
    return (int)symbol < number ? 1 : 0;
}

void sumOfHigherThanSymbol(char& const symbol, int*& numbers, int const length) {
    int count = 0;
    for (int i = 0; i < length; ++i) {
        if (isHigher(symbol, numbers[i]))
            count += 1;
    }
    std::cout << "Sum: " << count;
}

void task2() {
    int N;
    std::cout << "Input N: ";
    std::cin >> N;
    validation(N);
    int* numbers = new int[N];
    inputNumbers(numbers, N);

    char symbol;
    std::cout << "Input a symbol: ";
    std::cin >> symbol;
    sumOfHigherThanSymbol(symbol, numbers, N);

    delete[] numbers;
}
int main()
{
	task2();
	return 0;
}