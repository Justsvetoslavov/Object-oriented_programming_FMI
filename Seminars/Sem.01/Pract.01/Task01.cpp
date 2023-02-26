#include <iostream>

using std::cin, std::cout, std::endl;

int lowerByPointer(const int *num1, const int *num2) {
    return *num1 < *num2 ? *num1 : *num2;
}

int lowerByReference(const int &num1, const int &num2) {
    return lowerByPointer(&num1, &num2);
}

int lowerByReference(int &num1, int &num2) {
    return lowerByPointer(&num1, &num2);
}

int main() {
    int num1, num2;
    const int number3 = 3;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    //Invokes the lowerByReference(const int &, const int &) function because the arguments are constant
    cout << "The lower by ref number is " << lowerByReference(num1, num2) << endl;
    //Invokes the lowerByReference(int &, int &) function because the arguments are not constant
    cout << "The lower by ref number is " << lowerByReference(num1, number3) << endl;
    cout << "The lower by pointer number is " << lowerByPointer(&num1, &num2) << endl;
    return 0;
}
