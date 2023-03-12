#include <iostream>
#include <fstream>
#include <cassert>

const char PATH[] = R"(C:\Users\Nikita\CLionProjects\untitled1\practice2\Task06.cpp)";

int main() {
    std::fstream me(PATH, std::ios::in);
    assert(me.is_open());
    char reader;
    while (me.get(reader))
        std::cout << reader;
    me.close();
}
