#include <iostream>

struct complexNumber
{
    int real;
    int imaginary;
};

complexNumber add(const complexNumber a, const complexNumber b)
{
    complexNumber sum;
    sum.real = a.real + b.real;
    sum.imaginary = a.imaginary + b.imaginary;
    return sum;
}

void printComplexNum(const complexNumber num)
{
    std::cout << num.real << " + " << num.imaginary << "i" << std::endl;
}

int main()
{
    complexNumber a = { 2,4 };
    complexNumber b = { 1,5 };
    complexNumber sum = add(a, b);
    std::cout << "Number 1: ";
    printComplexNum(a);
    std::cout << "Number 2: ";
    printComplexNum(b);
    std::cout << "Their sum: ";
    printComplexNum(sum);
    
    return 0;
}