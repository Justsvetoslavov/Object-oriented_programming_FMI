#include <iostream>
#include <fstream>

const int BUFFER_SIZE = 256;

int main()
{
	std::ifstream myFileToRead("Task02.cpp");
	std::ofstream myFileToWrite("s2.cpp");

	if (!myFileToRead.is_open() || !myFileToWrite.is_open()) {
		std::cout << "Error!";
		return -1;
	}

	while (!myFileToRead.eof()) {
		char buffer[BUFFER_SIZE];
		myFileToRead.getline(buffer, BUFFER_SIZE);
		myFileToWrite << buffer << std::endl;
	}

	myFileToRead.close();
	myFileToWrite.close();

}