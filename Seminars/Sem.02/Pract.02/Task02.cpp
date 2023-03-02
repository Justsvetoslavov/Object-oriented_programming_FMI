#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;

int CharArrayLength(char*);
int LengthOfFile(const char*);

int main() {
	
}

int CharArrayLength(char* arr) {
	int length = 0;
	while (*arr++ != '\0') length++;
	return length;
}

int LengthOfFile(const char* fileName) {
	ifstream fileToRead(fileName);
	if (!fileToRead.is_open())
	{
		cout << "Couldn't open " << fileName << endl;
		return 0;
	}
	int result = 0;
	while (!fileToRead.eof())
	{
		char buffer[1024];
		fileToRead.getline(buffer, 1024);
		result += CharArrayLength(buffer);
	}
	return result;
}
