#include <iostream>
#include <fstream>

size_t const LINE_SIZE = 256;

int main() {
	std::ifstream source("Task06.cpp");
	while (!source.eof())
	{
		char buff[LINE_SIZE];
		source.getline(buff, 256);
		std::cout << buff << std::endl;
	}
}