#include <iostream>
#include <fstream>

using std::cin, std::cout, std::endl, std::ofstream, std::ifstream, std::fstream;

const char *FILE_NAME = "results.txt";

void inputSumAndProductOfThreeNumbersInFile(fstream &file) {
    int a, b, c;
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;
    file << a + b + c << " " << a * b * c;
}

void readSumAndProductOfThreeNumbersFromFile(fstream &file) {
    int sum, product;
    file >> sum >> product;
    cout << "Te difference between the sum and the product is: " << sum - product << endl;
}

int main() {
    //fstream does not create a file if it does not exist
    //so we need to create it manually.
    fstream file(FILE_NAME);
    if (!file.is_open()) {
        cout << "File is not open" << endl;
        return -1;
    }

    inputSumAndProductOfThreeNumbersInFile(file);
    readSumAndProductOfThreeNumbersFromFile(file);

    file.close();
    return 0;
}
