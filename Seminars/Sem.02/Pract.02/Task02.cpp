#include <iostream>
#include <fstream>

const char* FILE_NAME = "result.txt";

unsigned int lenghtOfFile()
{
    std::fstream file(FILE_NAME);
    unsigned int lenght = 0;
    char c;
    while(!file.eof())
    {
        file >> c;
        lenght += 1;
    }
    return lenght;
}

int main()
{
    std::ifstream file(FILE_NAME);
    if(!file.is_open())
    {
        std::cout << "Error!" << std::endl;
        return -1;
    }
    unsigned int lenght = lenghtOfFile();
    std::cout << lenght;

    file.close();
    return 0;
}