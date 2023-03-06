//Gabriela Mladenova
//SI
//Group 1
//FN: 3MI0600225

#include <iostream>
#include <fstream>

const char FILENAME[] = "result.txt";

size_t lengthOfFile(const char NAME[])
{
    std::ifstream file(NAME);
    if (!file.is_open())
    {
        std::cout << "ERROR! The file could not be opened! ";
        return 0;
    }

    file.seekg(0, std::ios::end);

    size_t currentPosition = file.tellg();

    file.close();

    return currentPosition;
}

int main()
{
    std::cout << lengthOfFile(FILENAME);

    return 0;
}
