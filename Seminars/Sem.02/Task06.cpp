#include <iostream>
#include <fstream>

const unsigned int BUFFER_SIZE = 512;

void printLine(const char line[])
{
    int idx = 0;

    while (line[idx] != '\0' && idx < BUFFER_SIZE)
    {
        std::cout << line[idx++];
    }

    std::cout << std::endl;
}

int main()
{
    std::ifstream file("Task06.cpp");

    if (!file.is_open())
    {
        return 1;
    }

    while (!file.eof())
    {
        char line[BUFFER_SIZE] = {'\0'};

        file.getline(line, BUFFER_SIZE);

        printLine(line);
    }

    file.close();
    std::getchar();

    return 0;
}