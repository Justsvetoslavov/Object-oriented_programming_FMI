#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 256;
char path[MAX_SIZE] = "C:\\Users\\boris\\source\\repos\\zadachki\\zadachki\\zadachki.cpp";

int main()
{
	ifstream stream(path);

	char buffer[MAX_SIZE];
	while (!stream.eof())
	{
		stream.getline(buffer, MAX_SIZE);
		cout << buffer << '\n';
	}

	return 0;
}