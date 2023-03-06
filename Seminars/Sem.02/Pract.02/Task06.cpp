//Gabriela Mladenova
//SI
//Group 1
//FN: 3MI0600225

#include <iostream>
#include <fstream>

const int BUFFSIZE = 1024;
const char FILENAME[] = "Task06.cpp";

void printSourceCode(const char FILENAME[])
{
    std::ifstream writeInFile(FILENAME);

    if (!writeInFile.is_open())
    {
        std::cout << "ERROR! The file could not be opened! ";
        return;
    }

    while (!writeInFile.eof())
    {
        char buffer[BUFFSIZE];
        writeInFile.getline(buffer, BUFFSIZE);
        std::cout << buffer << std::endl;
    }

    writeInFile.close();
}

int main()
{
    printSourceCode(FILENAME);
}
