#include <iostream>
#include <fstream>

const char* FILE_NAME = "result.txt";

void writeNumbersToFile(const char* fileName, const int numbersCount)
{
	std::ofstream myFile(fileName);
	int prod = 1;
	int num;

	if (myFile.is_open())
	{
		for (size_t i = 0; i < numbersCount; i++)
		{
			std::cin >> num;
			prod *= num;
			myFile << num << " ";
		}

		myFile << prod;
	}

	myFile.close();
}

int getDiffBetweenSumAndProd(const char* fileName, const int numbersCount)
{
	int sum = 0;
	int prod = 0;
	std::ifstream myFile(fileName);

	if (myFile.is_open())
	{
		int num;
		for (size_t i = 0; i < numbersCount; i++)
		{
			myFile >> num;
			sum += num;
		}

		myFile >> prod;
	}

	return (sum - prod);
}

int main()
{
	writeNumbersToFile(FILE_NAME, 3);

	std::cout << getDiffBetweenSumAndProd(FILE_NAME, 3);
}