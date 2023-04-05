#include "String.h"
#include <iostream>

int main() {
    String str1("1234");
    String str2("test");
    String str3 = str1 + str2;
    str3.append('9');
    str3[2] = 'F';
    std::cout << str3[2];
    std::cout << std::endl << str3.length() << std::endl;
    str3 += str3;
    std::cout << str3.c_str() << std::endl;
    if (str1 != str2) {
        std::cout << ")";
    }
    if (str1 >= str2)
        std::cout << '(';
    std::cout << str3.empty();
    str3.clear();
    std::cout << str3.empty();
    std::cout << str3.c_str();
};