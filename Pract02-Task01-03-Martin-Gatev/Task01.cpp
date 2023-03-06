#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;

void PrintSubstraction(const char* fileName)
{
	std::ifstream ReadFile(fileName);

	if (!ReadFile.is_open())
	{
		return;
	}

	double sum{}, mult{};

	ReadFile >> sum >> mult;

	cout << endl << sum - mult;

	ReadFile.close();
}

int main()
{
	double a, b, c;

	const char name[11] = "result.txt";

	std::ofstream WriteFile(name);

	if (!WriteFile.is_open())
	{
		return -1;
	}

	cin >> a >> b >> c;

	WriteFile << a + b + c << ", " << a * b * c << endl;

	PrintSubstraction(name);

	WriteFile.close();

	return 0;
}