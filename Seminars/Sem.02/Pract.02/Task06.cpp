#include <iostream>
#include <fstream>

const int BUFF_SIZE = 1024;

void printFile(const char fileName[]) {
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cout << "Error\n";
        return;
    }

    while (!file.eof()) {
        char buff[BUFF_SIZE];
        file.getline(buff, BUFF_SIZE);
        std::cout << buff << "\n";
    }

    file.close();
}

int main()
{
    printFile("Task06.cpp");
}
