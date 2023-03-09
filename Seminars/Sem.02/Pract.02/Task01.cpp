//Gabriela Mladenova
//SI
//Group 1
//FN: 3MI0600225

#include <iostream>
#include <fstream>

const char FILENAME[] = "result.txt";

int readFromFile(const char NAME[], int substract)
{
    int sum;
    int multiplication;

    std::ifstream readFromFile(NAME);
    if (!readFromFile.is_open())
    {
        std::cout << "ERROR! The file could not be opened! ";
        return 0;
    }

    readFromFile >> sum >> multiplication;
    substract = sum - multiplication;

    readFromFile.close();

    return substract;
}

int main()
{
    int number1;
    std::cout << "Enter the first number: ";
    std::cin >> number1;

    int number2;
    std::cout << "Enter the second number: ";
    std::cin >> number2;

    int number3;
    std::cout << "Enter the third number: ";
    std::cin >> number3;

    int sum = number1 + number2 + number3;
    int multiplication = number1 * number2 * number3;
    int substract = 0;

    std::ofstream writeInFile(FILENAME);
    if (!writeInFile.is_open())
    {
        std::cout << "ERROR! The file could not be opened! ";
        return 0;
    }

    writeInFile << sum << " " << multiplication;

    writeInFile.close();

    std::cout << "The substract of the sum and the multiplication product of the numbers is: " <<
        readFromFile(FILENAME, substract);

    return 0;
}
