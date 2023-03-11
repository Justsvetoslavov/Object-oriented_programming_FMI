#include <iostream>
using std:: cout;
using std:: cin;

struct complexNum
{
    int realPart;
    int imPart;
};

complexNum sum (const complexNum& firstN, const complexNum& secondN)
{
    complexNum sum;
    sum.realPart = firstN.realPart + secondN.realPart;
    sum.imPart = firstN.imPart + secondN.imPart;

    return sum;
}

void printComplexNum(const complexNum& num)
{
    cout << num.realPart << " + " << num.imPart << "i" << '\n';
}

int main()
{
    const complexNum FIRSTNUM = {4, 9};
    const complexNum SECONDNUM = {3, 2};
    
    printComplexNum(sum(FIRSTNUM, SECONDNUM));
}