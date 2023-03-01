#include <fstream>
#include <iostream>

size_t lengthOfFile(const char *filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
        return 0;

    file.seekg(0, std::ios::end);
    size_t pos = file.tellg();

    file.close();

    return pos;
}