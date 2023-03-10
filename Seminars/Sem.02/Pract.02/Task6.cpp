#include <iostream>
#include <fstream>

using std::cin, std::cout, std::endl, std::ifstream, std::ofstream;

const char FILE_NAME[] = "Task6.cpp";

int main() {

    ifstream file(FILE_NAME);
    ofstream fileO("Task6.txt");

    if (!file.is_open() || !fileO.is_open()) {
        cout << "Error";
        return -1;
    }

    while (!file.eof()) {
        char str[1024];
        file.getline(str, 1024);

        fileO << str << endl;
    }

    file.close();
    fileO.close();

    return 0;
}