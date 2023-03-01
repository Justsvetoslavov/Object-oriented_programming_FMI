#include <iostream>
#include <fstream>

const char* FILE_NAME = "result.txt";

void getNumInFile()
{
    std::fstream file(FILE_NAME);
    int a, b, c;
    std::cin >> a >> b >> c;
    int sum = a + b + c;
    file << sum << " " << a * b * c;
}

void getSumProductInFile()
{
    std::fstream  file(FILE_NAME);
    int sum;
    int product;
    file >> sum >> product;
    std::cout << sum << " " << product;
}

int main()
{
    std::ifstream file(FILE_NAME);
    
    if(!file.is_open())
    {
        std::cout << "Error!" << std::endl;
        return -1;
    }
    getNumInFile();
    getSumProductInFile();
    file.close();
    return 0;
}