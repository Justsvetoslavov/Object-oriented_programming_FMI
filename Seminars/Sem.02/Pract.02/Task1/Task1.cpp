#include <iostream>
#include <fstream>

//От стандартния вход се прочитат три числа. Запишете във файл "result.txt"сумата и произведението им.
//Направете функция, която извежда на стандартния изход разликата на сумата и произведението, прочетени от файла "result.txt".
//Коректността на данните във файла, който четете, е гарантирана.

int sumOfNumbers(const int& num1, const int& num2, const int& num3)
{
    return num1 + num2 + num3;
}

int multiplicationOfNumbers(const int& num1, const int& num2, const int& num3)
{
    return num1 * num2 * num3;
}

int differenceOfSumAndMultiplication(const int& sum, const int& multiplication)
{
    return sum - multiplication;
}

void writeToFile(const int& num1, const int& num2, const int& num3)
{
    int sum = sumOfNumbers(num1, num2, num3);
    int multiplication = multiplicationOfNumbers(num1, num2, num3);

    std::ofstream resultFile("result.txt");

    if (!resultFile.is_open())
    {
        std::cout << "Error ocurred when trying to open the file." << std::endl;

        return;
    }

    resultFile << sum << '\n' << multiplication;

    resultFile.close();
}

int readFromFileAndCalculateDifference()
{
    std::ifstream file("result.txt");

    if (!file.is_open())
    {
        std::cout << "Error ocurred when trying to open the file." << std::endl;

        return -1;
    }

    int results[2];
    int i = 0;
    int difference;

    while (!file.eof())
    {
        int number;
        file >> number;
        results[i] = number;
        i++;
    }

    difference = differenceOfSumAndMultiplication(results[0], results[1]);

    file.close();

    return difference;
}

int main()
{
    int num1, num2, num3, difference;
    std::cout << "Enter three numbers: ";
    std::cin >> num1 >> num2 >> num3;

    writeToFile(num1, num2, num3);

    difference = readFromFileAndCalculateDifference();

    std::cout << difference << std::endl;

    return 0;
}
