#include <iostream>
#include <fstream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

const int MAX_RELATIONS = 25;
const int MAX_LENGTH_ARR = 20;
const int ASCII_ZERO = 48;

struct Pair
{
	double a;
	double b;
};

struct Relation
{
	Pair relations[MAX_RELATIONS];
	int size;
};

void SetDefaultValues(char* arr)
{
	if (arr == nullptr)
	{
		return;
	}

	for (size_t i = 0; i < MAX_LENGTH_ARR; i++)
	{
		arr[i] = '\0';
	}
}

unsigned int GetNumberLength(const char* arr)
{
	if (arr == nullptr)
	{
		return -1;
	}

	unsigned int size{};

	while (arr[size] != '\0')
	{
		size++;
	}

	return size;
}

int DigitsBeforeDot(const char* arr)
{
	if (arr == nullptr)
	{
		return -1;
	}

	int counter{};

	while (arr[counter] != '.')
	{
		counter++;
	}

	return counter;
}

bool IsDouble(const char* arr, const int size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == '.')
		{
			return true;
		}
	}

	return false;
}

double CharToDouble(const char* arr, const int size)
{
	if (arr == nullptr)
	{
		return -1;
	}

	bool isDouble = IsDouble(arr, size);

	if (isDouble)
	{
		unsigned int digBeforeDot = DigitsBeforeDot(arr);

		int multiplier = digBeforeDot - 1;

		double num{};

		for (size_t i = 0; i < digBeforeDot; i++)
		{
			num += (arr[i] - ASCII_ZERO) * pow(10, multiplier);
			multiplier--;
		}

		num += (double)(arr[size - 1] - ASCII_ZERO) / 10;

		return num;
	}

	else
	{
		double num{};

		int multiplier = size - 1;

		for (size_t i = 0; i < size; i++)
		{
			num += (arr[i] - ASCII_ZERO) * pow(10, multiplier);
			multiplier--;
		}

		return num;
	}

}

void ReadRelations(Relation& relation, const char* fileName)
{
	std::ifstream ReadFile(fileName);

	if (!ReadFile.is_open())
	{
		return;
	}

	char temp[MAX_LENGTH_ARR];

	SetDefaultValues(temp);

	unsigned int numberSize{};

	for (int i = 0; i < relation.size; i++)
	{
		ReadFile.seekg(1, std::ios::cur);

		ReadFile.getline(temp, MAX_LENGTH_ARR, ',');

		numberSize = GetNumberLength(temp);

		relation.relations[i].a = CharToDouble(temp, numberSize);

		SetDefaultValues(temp);

		ReadFile.seekg(1, std::ios::cur);

		ReadFile.getline(temp, MAX_LENGTH_ARR, ')');

		numberSize = GetNumberLength(temp);

		relation.relations[i].b = CharToDouble(temp, numberSize);

		ReadFile.seekg(2, std::ios::cur);
	}

	ReadFile.close();
}

void WriteRelationToFile(const Relation& relation, const char* fileName)
{
	std::ofstream WriteFile(fileName);

	if (!WriteFile.is_open())
	{
		return;
	}

	for (int i = 0; i < relation.size; i++)
	{
		WriteFile << "(" << relation.relations[i].a << ", " <<
			relation.relations[i].b << ")" << "\n";
	}

	WriteFile.close();
}

int main()
{
	const char writeFileName[13] = "relation.txt";
	const char fileName[] = "read_relations.txt";

	Relation relation;

	relation.size = 8;

	ReadRelations(relation, fileName);

	WriteRelationToFile(relation, writeFileName);

	return 0;
}