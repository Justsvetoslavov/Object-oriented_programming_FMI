#include <iostream>

int biggestNumberByValue(int a, int b) {
    return (a > b ? a : b);
}

int biggestNumberByReference(const int& a, const int& b) {
    return biggestNumberByValue(a, b);
}

int biggestNumberByPointer(int* const a, int* const b) {
    return biggestNumberByValue(*a, *b);
}

void task1() {

    int a, b;

    std::cout << "First number: ";
    std::cin >> a;
    std::cout << "Second number: ";
    std::cin >> b;

    int* c = new int(a);
    int* d = new int(b);

    std::cout <<
    biggestNumberByPointer(c, d) << " " <<
    biggestNumberByReference(a, b) << " " <<
    biggestNumberByValue(a, b);

    delete c;
    delete d;
}

int main() {
    task1();
    return 0;
}