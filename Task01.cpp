#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

void print(ifstream& readFile)
{
    int sum, product;
    readFile >> sum >> product;
    cout << abs(sum - product);
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    ofstream writeFile("result_Task01.txt");
    if (!writeFile.is_open())
    {
        cout << "Error";
        return -1;
    }
    int sum = a + b + c;
    int product = a * b * c;
    writeFile << sum << endl << product;
    writeFile.close();
    ifstream readFile("result.txt");
    print(readFile);
    readFile.close();
}

