#include <iostream>
#include <fstream>

int main()
{
	
}

size_t LengthOfFile(std::ifstream& file) {
	size_t currentPos = file.tellg();
	file.seekg(0, std::ios::end);
	size_t toReturn = file.tellg();
	file.seekg(currentPos, std::ios::beg);
	return toReturn;
}