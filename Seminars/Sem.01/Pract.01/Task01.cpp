#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int minByValue(int a, int b)
{
    return a < b ? a : b;
}

int minByReference(const int& a,const int& b)
{
    return a < b ? a : b;
}

int minByPointer(int* a, int* b)
{
    return *a < *b ? *a : *b;
}

int main()
{
    int x = 5, y = 7;

    cout << minByValue(x, y) << endl;
    cout << minByReference(x, y) << endl;
    cout << minByPointer(&x, &y) << endl;
}

