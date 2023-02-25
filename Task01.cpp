#include <iostream>

using std::cout;
using std::endl;

int smallest_reference(int &num1, int &num2) {
    if (num1 > num2)
        return num2;
    return num1;
}

int smallest_pointers(const int *num1, const int *num2) {
    if (*num1 > *num2)
        return *num2;
    return *num1;
}

int main() {
    int a = 5, b = 7;
    cout << smallest_pointers(&a, &b) << endl;
    cout << smallest_reference(a, b);
}