#include "String.h"
#include<iostream>

int main() {

    String s1("hello");
    String s2 = "world";
    std::cout << "s1: " << s1.c_str() << std::endl; // output: s1: hello
    std::cout << "s2: " << s2.c_str() << std::endl; // output: s2: world

    s1 += s2;
    std::cout << "s1 after concatenation: " << s1.c_str() << std::endl; // output:helloworld

    std::cout << "s1 == s2? " << (s1 == s2) << std::endl; // output:0 (false)
    std::cout << "s1 < s2? " << (s1 < s2) << std::endl; // output:1 (true)
    std::cout << "s1 > s2? " << (s1 > s2) << std::endl; // output: 0 (false)
    std::cout << "s1 <= s2? " << (s1 <= s2) << std::endl; // output: 1 (true)
    std::cout << "s1 >= s2? " << (s1 >= s2) << std::endl; // output: 0 (false)

    std::cout << "Length of s2: " << s2.length() << std::endl; //5

    s2.append('!');
    const char* content = s2.c_str();
    std::cout << "Content of s2: " << content << std::endl;// world!

    s2.clear(); 

    if (s2.empty()) {
        std::cout << "s2 is empty" << std::endl;
    }
    else {
        std::cout << "s2 is not empty" << std::endl;
    }

    return 0;
}