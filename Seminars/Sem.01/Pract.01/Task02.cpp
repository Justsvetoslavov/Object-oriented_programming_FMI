// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void greaterThanSymbol(int* arr, char c, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > c) {
            cout << arr[i] << " is greater than the symbol '" << c << "'!" << endl;
        }

    }
}
int main()
{
    int n;
    cout << "Enter the number of numbers you want to have: ";
    cin >> n;
    int* arr = new int[n];
    char c;
    cout << "Enter the numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter a symbol: ";
    cin >> c;
    greaterThanSymbol(arr, c, n);
    delete[] arr;
}

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
