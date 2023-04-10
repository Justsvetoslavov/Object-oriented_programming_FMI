#include <iostream>
#include "MyString.h"

int main()
{
    MyString str = "1234";

    str.resize(20);

    std::cout << str;
}