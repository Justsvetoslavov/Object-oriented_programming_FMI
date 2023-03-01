//Gabriela Mladenova
//SI
//Group 1
//FN: 3MI0600225

#include <iostream>

int minNumber1(const int& number1,const int& number2)
{
    if (number1 < number2)
    {
        return number1;
    }
    if (number2 < number1)
    {
        return number2;
    }
    return number1;
}
int minNumber2(const int* number1, const int* number2)
{
    if (*number1 < *number2)
    {
        return *number1;
    }
    else if (*number2 < *number1)
    {
        return *number2;
    }
    return *number1;
}
int main()
{
    int number1;
    std::cout << "Enter the first number: ";
    std::cin >> number1;
    int number2;
    std::cout << "Enter the second number: ";
    std::cin >> number2;

    std::cout << "First function/The smaller of the two numbers is: ";
    std::cout << minNumber1(number1, number2);
    std::cout << std::endl;
    std::cout << "Second function/The smaller of the two numbers is: ";
    std::cout << minNumber2(&number1, &number2);

    return 0;
}
