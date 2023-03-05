#include <iostream>
#include <fstream>

const char EXAMPLE_FILE_NAME[] = "example.txt";

void initExampleFile() {
    std::ofstream myFile(EXAMPLE_FILE_NAME);

    if (!myFile.is_open()) {
        return;
    }

    myFile << "dhjdicnjduwjhujhujhjsuhufjhdhjhuejhdeu27727277772727272232dfsdsfssfddsfs"; //72

    myFile.close();
}

int lengthOfFile(const char fileName[]) {
    std::ifstream myFile(fileName);

    if (!myFile.is_open()) {
        return -1;
    }

    myFile.seekg(0, myFile.end);
    return myFile.tellg();
}

int main()
{
    initExampleFile();
    std::cout << "Length of file: " << lengthOfFile(EXAMPLE_FILE_NAME);
}
