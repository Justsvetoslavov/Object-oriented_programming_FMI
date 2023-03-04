#include <iostream>
#include <fstream>

const int BUFF_SIZE = 1024;
const char* FILE_NAME = "Task05.cpp";

void printProgramOwnCode()
{
	std::ifstream myFile(FILE_NAME);

	if (myFile.is_open())
	{
		int prevPos = myFile.tellg();
		myFile.seekg(0, std::ios::beg);

		char buffer[BUFF_SIZE];

		while (!myFile.eof())
		{
			myFile.getline(buffer, BUFF_SIZE);
			std::cout << buffer << std::endl;
		}

		myFile.seekg(prevPos);
	}

	myFile.close();
}