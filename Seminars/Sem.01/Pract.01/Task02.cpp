#include <iostream>

int  numbersBiggerThanChar(const int arr[], const int size, const char ch) {
    int ctr = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > ch) {
            ctr++;
        }
    }
    return ctr;
}

int main()
{
    int N;
    std::cin >> N;
    int* arr = new int[N];

    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    char ch;
    std::cin >> ch;

    std::cout << numbersBiggerThanChar(arr, N, ch) << " ";
    delete[] arr;

    //int arr2[] = { 1, 2, 3, 4, 87, 95, 107, 281, 130 };
    //char ch2 = 'a';
    //std::cout << numbersBiggerThanChar(arr2, sizeof(arr2) / sizeof(int), 'S');
}

