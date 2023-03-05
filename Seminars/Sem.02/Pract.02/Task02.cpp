#include <iostream>
#include <fstream>

size_t lengthOfFile(const char* fileName)
{
    std::ifstream myFile(fileName);

    if (!myFile.is_open()) {
        std::cout << "Error!";
        return -1;
    }

    myFile.seekg(0, std::ios::end);
    size_t currentPos = myFile.tellg();
    myFile.close();

    return currentPos;
}

int main()
{
    char fileName[]{ "testFile.txt" };

    std::cout << lengthOfFile("testFile.txt");
}
