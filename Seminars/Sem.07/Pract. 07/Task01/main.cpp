#include <iostream>

#include "String.h"

int main()
{
    String str("1234");
    String str2("sjjs");
    String str3("58747203877522905802");
    String str4("58747203877522905801");
    String str5("58747203877522905802");
    String str6("58747203877522905809");

    str.append('1');
    str += str2;
    str[0] = 'a';
    str.print();
     
    std::cout << (str3 == str5) << std::endl;
    std::cout << (str3 <= str5) << std::endl;
    std::cout << (str3 < str5) << std::endl;
    std::cout << (str3 < str4) << std::endl;
    std::cout << (str3 == str4) << std::endl;
    std::cout << (str3 != str4) << std::endl;
    std::cout << str3.compare(str2) << std::endl;

    std::cout << std::endl;
    std::cout << str6.length() << std::endl;
    std::cout << str6.empty() << std::endl;
    str6.clear();
    std::cout << str6.empty() << std::endl;
    str6.print();

    (str2 + str3 + str4 + str5).print();
}

