#include <iostream>
#include <fstream>

int main()
{
    const char FILE_NAME[] = "result.txt";

    std::ifstream file(FILE_NAME);

    if (!file.is_open())
    {
        return 1;
    }

    unsigned int t = file.tellg();

    file.seekg(0, std::ios::end);

    std::cout << file.tellg();

    file.seekg(t, std::ios::beg);

    file.close();

    return 0;
}