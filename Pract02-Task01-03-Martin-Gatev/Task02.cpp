#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;

int LengthOfFile(const char* fileName)
{
	std::ifstream ReadFile(fileName);

	if (!ReadFile.is_open())
	{
		return -1;
	}

	ReadFile.seekg(0, std::ios::end);

	int length = ReadFile.tellg();

	ReadFile.close();

	return length;
}

int main()
{
	const char name[13] = "template.txt";

	cout << LengthOfFile(name);

	return 0;
}