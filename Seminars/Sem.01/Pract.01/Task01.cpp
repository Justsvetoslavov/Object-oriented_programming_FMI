#include <iostream>
using std:: cin;
using std:: cout;

int smallerValue(int a, int b)
{
    if(a<b)
    {
        return a;
    }
    return b;
}
int smallerValueConst(const int a, const int b)
{
    if(a<b)
    {
        return a;
    }

    return b;
}

int smallerPionter(const int* FN, const int* SN)
{
    if((*FN)<(*SN))
    {
        return (*FN);
    }

    return (*SN);
}

int smallerReference(const int& FIRSTNUM, const int& SECONDNUM)
{
    if(FIRSTNUM<SECONDNUM)
    {
        return FIRSTNUM;
    }

    return SECONDNUM;
}

int main()
{
    int a,b;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    const int FIRSTNUM = 37, SECONDNUM = 96;
    const int* FN = &FIRSTNUM;
    const int* SN = &SECONDNUM;
    int* pa = &a;
    int* pb = &b;
    cout << "Min number by Value: " << smallerValue(FIRSTNUM, SECONDNUM) << '\n';
    cout << "Min number by Value: " << smallerValue(a, b) << '\n';
    cout << "Min number by Value: " << smallerValueConst(FIRSTNUM, SECONDNUM) << '\n';
    cout << "Min number by Value: " << smallerValueConst(a,b) << '\n';

    //cout << "Min number by Pointer: " << smallerPionter(FIRSTNUM, SECONDNUM) << '\n'; -----> won't work
    cout << "Min number by Pointer: " << smallerPionter(FN, SN) << '\n';
    cout << "Min number by Pointer: " << smallerPionter(pa, pb) << '\n';
    //cout << "Min number by Reference: " << smallerPionter(a, b) << '\n';  ------> won't work

    //cout << "Min number by Reference: " << smallerReference(FN, SN) << '\n'; -----> wont work
    cout << "Min number by Reference: " << smallerReference(a, b) << '\n';
    cout << "Min number by Reference: " << smallerReference(FIRSTNUM, SECONDNUM) << '\n';
}