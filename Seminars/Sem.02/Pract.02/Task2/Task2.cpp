#include <iostream>
#include <fstream>

//Да се напише подходящо параметризирана функция lengthOfFile(...) която връща колко символа има в текстов файл.

int lengthOfFile(std::ifstream& file)
{
	int symbolsInFile = 0;
	char symbol;

	if (!file.is_open())
	{
		std::cout << "Error ocurred when trying to open the file." << std::endl;

		return -1;
	}

	while (file.get(symbol))
	{
		symbolsInFile++;
	}

	return symbolsInFile;
}

int main()
{
	int symbols;

	std::ifstream file("result.txt");

	symbols = lengthOfFile(file);

	std::cout << symbols << std::endl;

    return 0;
}
