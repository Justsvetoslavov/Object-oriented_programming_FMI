#include <iostream>

struct ComplexNumber
{
    int a;
    int b;
};

void inputComplexNum(ComplexNumber& num);
ComplexNumber sumOfTwoComplexNums(const ComplexNumber num1, const ComplexNumber num2);
void printComplexNumber(const ComplexNumber& num);

int main()
{
    ComplexNumber num1, num2;
    inputComplexNum(num1);
    inputComplexNum(num2);
    printComplexNumber(sumOfTwoComplexNums(num1, num2));
    return 0;
}

void inputComplexNum(ComplexNumber& num)
{
    std::cin >> num.a >> num.b;
}

ComplexNumber sumOfTwoComplexNums(const ComplexNumber num1, const ComplexNumber num2)
{
    ComplexNumber result;
    result.a = num1.a + num2.a;
    result.b = num1.b + num2.b;
    return result;
}

void printComplexNumber(const ComplexNumber& num)
{
    if(num.a == 0)
    {
        std::cout << num.b << "i";
        return;
    }
    if(num.b > 0)
    {
        std::cout << num.a << " + " << num.b << "i";
    }
    else if(num.b == 0)
    {
         std::cout << num.a;
    }
    else
    {
         std::cout << num.a << " - " << num.b * -1 << "i";
    }
}