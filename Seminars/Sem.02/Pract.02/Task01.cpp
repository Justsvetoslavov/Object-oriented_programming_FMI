#include <iostream>
#include <fstream>

using std::cin; 
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;

void PrintFileContent(const char*);

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	ofstream fileToWrite("result.txt");
	int product = a * b * c;
	int sum = a + b + c;
	fileToWrite << "Product: " << product << endl;
	fileToWrite << "Sum: " << sum << endl;
	const char* filename = "result.txt";
	PrintFileContent(filename);
}

void PrintFileContent(const char* fileName) {
	ifstream fileToRead(fileName);
	if (!fileToRead.is_open())
	{
		cout << "Couldn't open " << fileName << endl;
		return;
	}
	while (!fileToRead.eof())
	{
		char buffer[128];
		fileToRead.getline(buffer, 128);
		cout << buffer << endl;
	}
}