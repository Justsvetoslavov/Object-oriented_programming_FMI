#include <iostream>
#include <fstream>

using std::cin, std::cout, std::endl, std::ofstream, std::ifstream;


int lengthOfFile(ifstream &file) {
    int length = 0;
    while (!file.eof()) {
        char c;
        file >> c;
        length++;
    }
    return length;
}


int main() {
    ifstream file("results.txt");
    if (!file.is_open()) {
        cout << "File is not open" << endl;
        return -1;
    }
    cout << "The length of file is: " << lengthOfFile(file);
    file.close();
    return 0;
}
