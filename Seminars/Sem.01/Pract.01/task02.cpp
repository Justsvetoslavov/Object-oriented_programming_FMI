#include <iostream>

using namespace std;

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
