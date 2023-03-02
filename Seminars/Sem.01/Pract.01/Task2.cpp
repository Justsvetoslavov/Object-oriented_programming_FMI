#include <iostream>
using std::cin;
using std::cout;

void inputNumbers(int* arr, const int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter a number: ";
        cin >> arr[i];
    }
}

int findCount(const int* arr, const int size, int symbolASCIICode) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > symbolASCIICode) {
            count++;
        }
    }

    return count;
}

int main() {

    int n;

    cin >> n;

    int* numbers = new int[n];

    inputNumbers(numbers, n);

    char symbol;
    cin >> symbol;

    int count = findCount(numbers, n, (int) symbol);

    cout << "Count: " << count;

    delete[] numbers;

    return 0;
}