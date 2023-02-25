#include <iostream>

//Value
int smallerNum1(const int a, const int b) {
    if (a < b) {
        return a;
    }
    return b;
}

//Reference
int smallerNum2(const int& a, const int& b) {
    if (a < b) {
        return a;
    }
    return b;
}

//Pointer
int smallerNum3(const int* a, const int* b) {
    if (*a < *b) {
        return *a;
    }
    return *b;
}

int main()
{
    int a = 10;
    int b = 5;

    smallerNum1(a, b);
    smallerNum2(a, b);
    smallerNum3(&a, &b);

    smallerNum1(1, 2);
    smallerNum2(1, 2);
    //smallerNum3(1, 2);

    const int c = 13, d = 23;
    smallerNum1(c, d);
    smallerNum2(c, d);
    smallerNum3(&c, &d);

    int* e, *f;
    e = &a;
    f = &b;

    smallerNum1(*e, *f);
    smallerNum2(*e, *f);
    smallerNum3(e, f);

    int& g = a;
    int& h = b;

    smallerNum1(g, h);
    smallerNum2(g, h);
    smallerNum3(&g, &h);
}


