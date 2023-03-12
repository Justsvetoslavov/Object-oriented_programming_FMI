#include <iostream>
#include <fstream>

using std::cout, std::ifstream, std::ios;

const char FILE_NAME[] = "result.txt";

int lengthOfFile(ifstream& file) {
    file.seekg(0, ios::end);

    return file.tellg();
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