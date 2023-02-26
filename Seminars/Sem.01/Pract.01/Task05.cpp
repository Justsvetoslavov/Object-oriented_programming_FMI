#include <iostream>

struct complexNumber
{
    int number;
    int iNum;
};

complexNumber sumOfTwoCompNums(complexNumber& num1, complexNumber& num2)
{
    complexNumber result{(result.number = num1.number + num2.number), result.iNum = num1.iNum + num2.iNum};
    return result;
}

void printCompNum(complexNumber num)
{
    std::cout << num.number << " + " << num.iNum << "i" << std::endl;
}

int main()
{
    complexNumber num1 = { 1, 5 };
    complexNumber num2 = { 2, 6 };
    printCompNum(sumOfTwoCompNums(num1, num2));
}