#include <iostream>
#include <fstream>

const int BUFFER_SIZE = 256;

int main()
{
	std::ifstream myFileToRead("Task06.cpp");

	if (!myFileToRead.is_open()) {
		std::cout << "Error!";
		return -1;
	}

	while (!myFileToRead.eof()) {
		char buffer[BUFFER_SIZE];
		myFileToRead.getline(buffer, BUFFER_SIZE);
		std::cout << buffer << std::endl;
	}

	myFileToRead.close();
}
