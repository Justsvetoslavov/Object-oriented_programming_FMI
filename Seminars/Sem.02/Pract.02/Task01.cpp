#include <iostream>
#include <fstream>
using std::cin;
using std::cout; 
using std::endl;
using std::ifstream;
using std::ofstream; 
using std::fstream;

const char* FILE_NAME = {"result.txt"};

void sumAndMult(fstream &FILE_NAME)
{
    int a, b, c;
    cin >> a >> b >> c;
    int sum = a + b + c;
    int mult = a * b * c;
    FILE_NAME<< sum <<" "<< mult;
}

void printResult(fstream &FILE_NAME)
{
    int sum, mult;
    FILE_NAME >> sum >> mult;
    cout << mult - sum; 
}

int main ()
{
    fstream file(FILE_NAME);
    if(!file.is_open())
    {
        cout << "Error!" << endl;
        return -1;
    }

    sumAndMult(file);
    printResult(file);

    file.close();
}