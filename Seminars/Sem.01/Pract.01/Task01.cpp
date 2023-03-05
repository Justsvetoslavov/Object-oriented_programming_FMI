// ConsoleApplication35.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;
int bigSmall(int a, int b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

int smallBig(int& a, int& b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}
int idk(int a, int& c) {
    if (a > c) {
        return c;
    }
    else {
        return c;
    }
}
int kdi(int a, const int c) {
    if (a > c) {
        return a;
    }
    else {
        return c;
    }
}
int main()
{
    int a, b;
    cin >> a >> b;
    const int c = 5;
    cout << bigSmall(a, b) << endl;
    cout << smallBig(a, b) << endl;
    //cout << idk(b, c)<<endl;
    cout << kdi(a, c);
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
