#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int bigger_than_sym(int* arr, int size, char sym) {
    int res = 0;
    for (size_t i = 0; i < size; i++)
        if ((int)sym < arr[i])
            res++;
    return res;
}

void read_numbers(int* arr, int size) {
    for (int i = 0; i < size; i++)
        cin >> arr[i];
}

int main() {
    int n;
    char sym;
    cin >> n;
    int* arr = new int[n];
    read_numbers(arr, n);
    cin >> sym;
    cout << bigger_than_sym(arr, n, sym);
    delete[] arr;
}
