#include <iostream>
#include "String.h"

int main()
{
    String str1 = "Hello World!";
    str1.append(' ');
    str1.append('a');
    str1.append('b');
    str1.append('c');

    str1 += ". This is the += operator!";

    std::cout << str1 << "\n";

    str1.clear();

    str1.append('a');
    str1.append('b');
    str1.append('c');

    std::cout << "Empty: " << str1.empty() << "\n" << "Length: " << str1.length() << "\n";
    std::cout << "Equal: " << (str1 == "abc") << "\n";
    std::cout << "Equal: " << (str1 == "abc1") << "\n";

    str1[5] = 'a';

    return 0;
}
