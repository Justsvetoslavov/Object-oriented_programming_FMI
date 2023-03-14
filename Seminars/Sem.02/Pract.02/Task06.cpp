#include <iostream>
#include <fstream>

using std::cin, std::cout, std::endl, std::ofstream, std::ifstream;

const char *FILE_NAME = "main.cpp";

void printSourceCode(ifstream &file) {
    std::streampos size;
    size = file.tellg();
    char *sourceCode = new char[size];
    file.seekg(0, std::ios::beg);
    file.read(sourceCode, size);

    cout << sourceCode;
    delete[] sourceCode;
}

int main() {
    ifstream file(FILE_NAME, std::ios::ate);
    if (!file.is_open()) {
        cout << "File is not open" << endl;
        return -1;
    }

    printSourceCode(file);
    file.close();
    return 0;
}
