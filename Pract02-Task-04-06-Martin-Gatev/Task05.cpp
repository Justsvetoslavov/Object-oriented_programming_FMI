#include <iostream>
#include <fstream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

const int MAX_BUFFER_SIZE = 1024;

void PrintProgram(const char* fileName)
{
	std::ifstream ReadFile(fileName);

	if (!ReadFile.is_open())
	{
		return;
	}

	char buffer[MAX_BUFFER_SIZE];

	while (!ReadFile.eof())
	{
		ReadFile.getline(buffer, MAX_BUFFER_SIZE, '\n');
		cout << buffer << endl;
	}

	ReadFile.close();
}

int main()
{
	const char fileName[] = "Source.cpp";
	PrintProgram(fileName);

	return 0;
}