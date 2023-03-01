#include <iostream>
#include <fstream>
#include "assert.h"

int lengthOfFile(const char path[]) {
    std::fstream read_file(path, std::ios::in);
    assert(read_file.is_open());
    int length = 0;
    char rotator;
    while(read_file >> std::noskipws >> rotator)
        length++;
    return length;
}

int main() {
    std::cout << lengthOfFile("result.txt");
}