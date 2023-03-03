#include <iostream>

int minValue(const int num1, const int num2)
{
    return (num1 > num2 ? num2 : num1);
}

int minPointer(const int* num1, const int* num2)
{
    return minValue(*num1, *num2);
}

int minReference(const int& num1, const int& num2)
{
    return minValue(num1, num2);
}
int minReferenceNonConst(int& num1, int& num2)
{
    return minValue(num1, num2);
}

int main()
{
    int num1, num2;
    std::cout << "Enter two integers: ";
    std::cin >> num1 >> num2;

    std::cout << "Min number by value: " << minValue(num1, num2) << std::endl;
    std::cout << "Min number by reference (const): " << minReference(num1, num2) << std::endl;
    std::cout << "Min number by reference (non const): " << minReferenceNonConst(num1, num2) << std::endl;
    //std::cout << "Min number by reference (test with const): " << minReferenceNonConst(3, 6) << std::endl; - Cannot get constant values
    //It is possible to use both constant and non-constant values for constant parameters of a function,
    //but impossible to use constant values for non-constant parameters of a function.

    int* p1 = &num1, *p2 = &num2;
    std::cout << "Min number by pointer: " << minPointer(p1, p2) << std::endl;

    //The following won't work\
    // std::cout << "Min number by value: " << minValue(p1, p2) << std::endl;
    //std::cout << "Min number by reference: " << minReference(p1, p2) << std::endl;
    //std::cout << "Min number by pointer: " << minPointer(num1, num2) << std::endl;

    return 0;
}