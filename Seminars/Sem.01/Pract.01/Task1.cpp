#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int lowerNumber(int a, int b) {
    return a > b ? b : a;
}

int lowerNumberReferenceConst(const int& a, const int& b) {
    //a = 5;
    //b = -5;
    return a > b ? b : a;
}

int lowerNumberReference(int& a, int& b) {
    a = 10;
    b = 11;
    return a > b ? b : a;
}

int lowerNumberPointer(const int* a, const int* b) {
    return *a > *b ? *b : *a;
}

int main() {

    int a = 5;
    int b = 7;
    const int c = 10;

    cout << lowerNumber(a, b) << endl;
    cout << lowerNumberReference(a, b) << endl;
    cout << lowerNumberPointer(&a, &b) << endl;
    cout << lowerNumberReferenceConst(a, b) << endl;

    //cout << lowerNumberReference(a, c) << endl;
    cout << lowerNumberReference(a, b) << endl;
    //cout << lowerNumberReference(7, 5) << endl;

    cout << lowerNumberReferenceConst(a, c) << endl;
    cout << lowerNumberReferenceConst(a, b) << endl;
    cout << lowerNumberReferenceConst(7, 5) << endl;

    return 0;
}