#include <iostream>
#include <fstream>
#include "constants.h"

size_t GetLinesCount(std::ifstream& in)
{
	size_t counter = 0;
	while (!in.eof()) {
		char buffer[BUFFER_SIZE];
		in.getline(buffer, BUFFER_SIZE, '\n');
		counter++;
	}

	return counter;
}