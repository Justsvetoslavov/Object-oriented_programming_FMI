#include <iostream>
#include "String.h";

int main()
{
    String string;
    string = "Some example";
    std::cout << string.c_str() << std::endl;
    std::cout << "Size: " << string.GetSize() << std::endl;
    std::cout << "The 4th letter is: " << string[3] << std::endl;
    
    string.Append(' ');
    String str("here");
    string += str;
    std::cout << "Concatenated string: " << string.c_str() << std::endl;

    if (str == string)
        std::cout << "The strings are equal\n";
    else
        std::cout << "The strings aren't equal\n";

    if (str <= string)
        std::cout << "str is less or equal than string\n";
    else
        std::cout << "string is less or equal than str\n";
}

