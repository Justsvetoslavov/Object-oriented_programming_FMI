#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int lowerNumber(int a, int b) {
    return a > b ? b : a;
}

int lowerNumberReference(const int& a, const int& b) {
    return a > b ? b : a;
}

int lowerNumberPointer(const int* a, const int* b) {
    return *a > *b ? *b : *a;
}

int main() {

    int a = 5;
    int b = 7;

    cout << lowerNumber(a, b) << endl;
    cout << lowerNumberReference(a, b) << endl;
    cout << lowerNumberPointer(&a, &b) << endl;

    return 0;
}