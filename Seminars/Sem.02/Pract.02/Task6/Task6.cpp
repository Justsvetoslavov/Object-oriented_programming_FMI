#include <iostream>
#include <fstream>

const int MAX_BUFFER_SIZE = 1024;

int main()
{
    std::ifstream codeFile("Task6.cpp");

    if (!codeFile.is_open())
    {
        std::cout << "Error ocurred when trying to open the file." << std::endl;

        return -1;
    }

    while (!codeFile.eof())
    {
        char buff[MAX_BUFFER_SIZE];
        codeFile.getline(buff, MAX_BUFFER_SIZE);
        std::cout << buff << std::endl;
    }

    codeFile.close();

    return 0;
}
