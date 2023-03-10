#include <iostream>
#include <fstream>

using std::cout, std::ifstream;

const int BUFF_SIZE = 1024;
const char FILE_NAME[] = "result.txt";

int length(const char* str) {
    int counter = 0;
    for (int i = 0; str[i]; i++) {
        counter++;
    }

    return counter;
}

int lengthOfFile(ifstream& file) {
    int counter = 0;
    while (!file.eof()) {
        char buff[BUFF_SIZE];
        file.getline(buff, BUFF_SIZE);

        if (file.eof()) {
            counter += length(buff);
            continue;
        }

        counter += BUFF_SIZE - 1;
    }

    return counter;
}

int main() {

    ifstream file(FILE_NAME);

    if (!file.is_open()) {
        cout << "Error!";
        return -1;
    }

    cout << "Length: " << lengthOfFile(file);

    file.close();

    return 0;
}