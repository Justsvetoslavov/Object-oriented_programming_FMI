#include <iostream>
#include "MyString.h"

int main()
{
    MyString str = "aaa";
    MyString app = "bb";

    std::cout << str.at(0) << std::endl;
    std::cout << str[0] << std::endl;

    str.append("ccc");
    str += app;
    str += "some really long text causing resize bro";

    str.push_back('!');
    std::cout << str[str.size() - 1] << std::endl;

    str.pop_back();
    std::cout << str[str.size() - 1] << std::endl;

    str.shrink_to_fit();

    str = app;

    int stop = 0;
}