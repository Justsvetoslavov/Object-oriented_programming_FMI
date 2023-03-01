//Gabriela Mladenova
//SI
//Group 1
//FN: 3MI0600225

#include <iostream>

int countOfBiggerASCII(int* arr, int size, char symbol)
{
    int counter = 0;
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] > symbol)
        {
            ++counter;
        }
    }
    return counter;
}
int main()
{
    int N;
    std::cout << "Enter number of codes: ";
    std::cin >> N;
    int* codes = new int[N];
    for (int i = 0; i < N; ++i)
    {
        std::cin >> codes[i];
    }

    char symbol;
    std::cout << "Enter the symbol: ";
    std::cin >> symbol;

    std::cout << "The number of bigger codes than the code of the symbol is: ";
    std::cout << countOfBiggerASCII(codes, N, symbol);

    delete[] codes;

    return 0;
}
