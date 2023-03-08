#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

const char FILE_NAME[] = "result_Task01.txt";

void WriteFile(const char* fileName, int a, int b, int c, int sum, int multiply)
{
    ofstream writeFile(fileName);
    if (!writeFile.is_open())
    {
        cout << "Error";
        return;
    }
    writeFile << sum << " " << multiply;
    writeFile.close();
}

void ReadFile(const char fileName[], int sum, int multiply)
{
    ifstream readFile(fileName);
    if (!readFile.is_open())
    {
        cout << "Error";
        return;
    }
    readFile >> sum >> multiply;
    cout << abs(sum - multiply);
    readFile.close();
}



int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int sum, multiply;
    sum = a + b + c;
    multiply = a * b * c;
    WriteFile(FILE_NAME, a, b, c, sum, multiply);
    ReadFile(FILE_NAME, sum, multiply);
}

