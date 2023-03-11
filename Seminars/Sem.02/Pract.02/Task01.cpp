#include <iostream>
#include <fstream>

void readFromFile()
{
    int sum, mult;
    std::ifstream readFile("result.txt", std::ios::in);
    if(readFile.is_open())
    {
        readFile >> sum ;
        readFile >> mult;
    }
    readFile.close();
    std::cout << "Difference between the sum and the multiplication is: " << sum - mult << std:: endl;
}

int main()
{
    std:: cout << "Type three numbers: ";
    int firstNum, secondNum, thirdNum;
    std:: cin >> firstNum >> secondNum >> thirdNum;
    int sum = firstNum + secondNum + thirdNum;
    int mult = firstNum*secondNum*thirdNum;
    
    std::ofstream writeFile("result.txt", std::ios::out);
    if(writeFile.is_open())
    {
        writeFile << sum << std:: endl;
        writeFile << mult;
    }
    writeFile.close();

    readFromFile();

    return 0;
}