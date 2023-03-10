#include <iostream>
#include <fstream>

using std::cin, std::cout, std::endl, std::ifstream, std::ofstream;

const char FILE_NAME[] = "result.txt";

void input(ofstream& file) {
    int a, b, c;
    
    cout << "Input: ";
    cin >> a >> b >> c;

    file << a + b + c << " " << a * b * c;
}

void output(ifstream& file) {
    int a, b;

    file >> a >> b;

    cout << a - b;
}

int main() {

    ofstream fileO(FILE_NAME);

    if (!fileO.is_open()) {
        cout << "File is not open.";
        return -1;
    }

    input(fileO);

    fileO.close();

    ifstream fileI(FILE_NAME);

    output(fileI);

    fileI.close();

    return 0;
}