#include <iostream>
#include "MyString.h"

int main()
{
    // MyString str1 = "this is a short phrase.";
    // MyString str2 = "!!!";

    // std::cout << str1.substr(11, 7) << std::endl;

    // str1.replace(22, 1, 3, '!');
    // std::cout << str1 << std::endl;

    MyString str = "this is just a string.";
    std::cout << str.substr(10, 4) << std::endl; // "this is an example string."
    MyString str2 = "n example";

    // std::cout << str.replace(9, 5, str2) << std::endl;      // "this is an example string."
    // std::cout << str.replace(8, 10, "just a") << std::endl; // "this is just a string."
    std::cout << str.replace(21, 1, 3, '!') << std::endl; // "this is a short string!!!"
}