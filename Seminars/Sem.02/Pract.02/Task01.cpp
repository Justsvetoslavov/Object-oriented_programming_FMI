#include <iostream>
#include <fstream>

using std::cin;using  std::cout; using std::endl; using std::ofstream; using std::ifstream;

const char* FILE_NAME = "results.txt";

void inputSumAndProductOfThreeNumbersInFile() {
    //ofstream creates a file if it does not exist
    //so we do not need to create it manually
    ofstream file("results.txt");
    int a, b, c;
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;
    if (!file.is_open()) {
        cout << "File is not open" << endl;
        return;
    }
    file << a + b + c << " " << a * b * c;
    file.close();
}

void readSumAndProductOfThreeNumbersFromFile() {
    ifstream file("results.txt");
    if (!file.is_open()) {
        cout << "File is not open" << endl;
        return;
    }
    int sum, product;
    file >> sum >> product;
    cout << "The difference between the sum and the product is: " << sum - product << endl;
    file.close();
}

int main() {
    inputSumAndProductOfThreeNumbersInFile();
    readSumAndProductOfThreeNumbersFromFile();
    return 0;
}
